#include "Core.hpp"
#include "IGuiException.hpp"

void		usage(const std::string& name)
{
  std::cout << "usage: " << name << "  HEIGHT_BLOC  WIDTH_BLOC  GUI_PATH" << std::endl;
}

int		main(int argc, char **argv)
{
  if (argc == 4)
    {
      size_t	sizeX, sizeY;

      std::istringstream(argv[1]) >> sizeX;
      std::istringstream(argv[2]) >> sizeY;
      try {
	Core		game(sizeX, sizeY, argv[3]);
	game.launchGame();
      }
      catch (NibblerException &e) {
	std::cerr << e.what() << std::endl;
	return (1);
      }
      catch (IGuiException &e) {
	std::cerr << e.what() << std::endl;
	return (1);
      }
    }
  else
    usage(argv[0]);
  return (0);
}
