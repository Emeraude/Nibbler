#include "Core.hpp"

void		usage(const std::string& name)
{
  std::cout << "usage: " << name <<" __GUI_PATH__" << std::endl;
}

int		main(int argc, char **argv)
{
  if (argc == 4)
    {
      Core		game(argv[1], argv[2], argv[3]);
      game.launchGame();
    }
  else
    usage(argv[0]);
  return (0);
}
