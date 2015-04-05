#include <iostream>
#include <sys/ioctl.h>
#include "NCurseGui.hpp"

NCurseGui::NCurseGui(std::pair<std::size_t, std::size_t> dim)
{
  struct winsize w;
  if ((ioctl(0, TIOCGWINSZ, &w)) == -1)
    throw ResolutionException("Unable to get terminal resolution.");
  if (dim.first <= 5 || dim.second <= 5
      || dim.first > w.ws_row || dim.second > w.ws_col / 2)
    throw ResolutionException("Invalid resolution.");
  _paused = false;
  _width = dim.first * 2;
  _height = dim.second;
  initscr();
  start_color();
  init_pair(1, COLOR_BLACK, COLOR_GREEN);
  init_pair(2, COLOR_BLACK, COLOR_RED);
  init_pair(3, COLOR_BLACK, COLOR_BLUE);
  init_pair(4, COLOR_BLACK, COLOR_CYAN);
  init_pair(5, COLOR_BLACK, COLOR_YELLOW);
  raw();
  noecho();
  cbreak();
  curs_set(0);
  keypad(stdscr, TRUE);
  refresh();
  if (!(_win = newwin(_height + 1, _width + 2, 0, 0)))
    throw NCurseException("Unable to open the window.");
  box(_win, 0, 0);
}

NCurseGui::~NCurseGui()
{
}

int		NCurseGui::launchMenu()
{
  return 0;
}

int		NCurseGui::printGame(const Snake& snake, const Apple & apple)
{
  std::deque<std::pair<int, int> > s = snake.getSnake();
  std::deque<std::pair<int, int> >::const_iterator it = s.begin();
  int apple_color;

  if (apple.getAge() <= apple.getBonusAge())
    apple_color = 4;
  else if (apple.getAge() > apple.getRottenAge())
    apple_color = 5;
  else
    apple_color = 1;
  wborder(_win, '|', '|', '_', '_', ' ', ' ', '|', '|');
  wattron(_win, COLOR_PAIR(3));
  mvwprintw(_win, it->first + 1, it->second * 2 + 1, "  ");
  wattroff(_win, COLOR_PAIR(3));
  while (++it != s.end()) {
    wattron(_win, COLOR_PAIR(2));
    mvwprintw(_win, it->first + 1, it->second * 2 + 1, "  ");
    wattroff(_win, COLOR_PAIR(2));
  }
  wattron(_win, COLOR_PAIR(apple_color));
  mvwprintw(_win, apple.getApple().first + 1, apple.getApple().second * 2 + 1, "  ");
  wattroff(_win, COLOR_PAIR(apple_color));
  std::pair<size_t, size_t>   lastLink = snake.getLastChain();
  mvwprintw(_win, lastLink.first + 1, lastLink.second * 2 + 1, lastLink.first + 1 == _height ? "__" : "  ");
  wrefresh(_win);
  return 0;
}

int		NCurseGui::eventManager(Snake& snake)
{
  char c;

  nodelay(stdscr, true);
  do {
    c = getch();
    if (c == 4)
      snake.moveRight();
    if (c == 5)
      snake.moveLeft();
    if (c == 27 || c == 'q' || c == 'Q')
      return (0);
    if (c == 'p' || c == 'P')
      _paused ^= 1;
    usleep(10);
  } while (_paused);
  return 1;
}

int		NCurseGui::guiQuit()
{
  wborder(_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
  wrefresh(_win);
  delwin(_win);
  curs_set(1);
  noraw();
  echo();
  endwin();
  return 0;
}

extern "C"
{
  IGui*	loadGui(std::pair<size_t, size_t> dim)
  {
    return new NCurseGui(dim);
  }
}
