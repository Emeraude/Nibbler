#include "Core.hpp"

Core::Core()
{
  _dynLoader->loadGui("");
}

Core::~Core()
{

}

Core::Core(const Core &rhs __attribute__((unused)))
{
}

Core&		Core::operator=(const Core &rhs __attribute__((unused)))
{
  if (this != &rhs)
    {
    }
  return *this;
}

int		Core::launchGame()
{
  int		ret;

  ret = menu();
  if (!ret)
    return EXIT_SUCCESS;
  else if (ret == -1)
    return EXIT_FAILURE;
  ret = game();
  if (!ret)
    return EXIT_SUCCESS;
  return EXIT_FAILURE;
}

int		Core::menu()
{
  int		ret = 1;

  if (gui->createWindows(std::pair<int, int>(1000, 500)) == -1)
    return (-1);
  while (ret != 0 && ret != -1)
    ret = gui->launchMenu();
  return ret;
}

int		Core::game()
{
  int		ret = 1;

  while (ret != 0 && ret != -1)
    ret = gui->launchGame(_snake);
  return (ret);
}
