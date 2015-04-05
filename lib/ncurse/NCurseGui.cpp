#include <iostream>
#include "NCurseGui.hpp"

NCurseGui::NCurseGui(std::pair<std::size_t, std::size_t> dim)
{
  _width = dim.first * 2;
  _height = dim.second;
  _win = newwin(_height, _width, 0, 0);
  initscr();
  start_color();
  init_pair(1, COLOR_GREEN, COLOR_BLACK);
  init_pair(2, COLOR_BLACK, COLOR_RED);
  init_pair(3, COLOR_BLACK, COLOR_BLUE);
  raw();
  noecho();
  cbreak();
  curs_set(0);
  keypad(stdscr, TRUE);
  refresh();
  _win = newwin(_height + 2, _width + 2, 0, 0);
  box(_win, 0, 0);
  wborder(_win, '|', '|', '_', '_', ' ', ' ', '|', '|');
}

NCurseGui::~NCurseGui()
{
  wborder(_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
  wrefresh(_win);
  delwin(_win);
  curs_set(1);
  noraw();
  echo();
  endwin();
}

int		NCurseGui::launchMenu()
{
  return 0;
}


int		NCurseGui::printGame(const Snake& snake, const Apple & apple)
{
  std::deque<std::pair<int, int> > s = snake.getSnake();
  std::deque<std::pair<int, int> >::const_iterator it = s.begin();

  wattron(_win, COLOR_PAIR(3));
  mvwprintw(_win, it->first + 1, it->second * 2 + 1, " ");
  mvwprintw(_win, it->first + 1, it->second * 2 + 2, " ");
  wattroff(_win, COLOR_PAIR(3));
  while (++it != s.end()) {
    wattron(_win, COLOR_PAIR(2));
    mvwprintw(_win, it->first + 1, it->second * 2 + 1, " ");
    mvwprintw(_win, it->first + 1, it->second * 2 + 2, " ");
    wattroff(_win, COLOR_PAIR(2));
  }
  wattron(_win, COLOR_PAIR(1));
  mvwprintw(_win, apple.getApple().first + 1, apple.getApple().second * 2 + 1, "0");
  mvwprintw(_win, apple.getApple().first + 1, apple.getApple().second * 2 + 2, "0");
  wattroff(_win, COLOR_PAIR(1));
  std::pair<int, int>   lastLink = snake.getLastChain();
  mvwprintw(_win, lastLink.first + 1, lastLink.second * 2 + 1, " ");
  mvwprintw(_win, lastLink.first + 1, lastLink.second * 2 + 2, " ");
  wrefresh(_win);
  return 0;
}

int		NCurseGui::eventManager(Snake& snake)
{
  char c;

  nodelay(stdscr, true);
  c = getch();
  if (c == 4)
    snake.moveRight();
  if (c == 5)
    snake.moveLeft();
  if (c == 27)
    return (0);
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
