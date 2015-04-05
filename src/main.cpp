#include "Core.hpp"

void		usage(const std::string& name)
{
  std::cout << "usage: " << name <<" __GUI_PATH__" << std::endl;
}

int		main(int argc, char **argv)
{
  if (argc == 4)
    {
      size_t	sizeX, sizeY;

      std::istringstream(argv[1]) >> sizeX;
      std::istringstream(argv[2]) >> sizeY;
      Core		game(sizeX, sizeY, argv[3]);
      game.launchGame();
    }
  else
    usage(argv[0]);
  return (0);
}
