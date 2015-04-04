#ifndef DYNAMICLOADER_HPP
# define DYNAMICLOADER_HPP

# include <string>
# include "IGui.hpp"

class DynamicLoader
{
private:
  void	*_handle;
  IGui	*_gui;

public:
  DynamicLoader();
  ~DynamicLoader();
  DynamicLoader(const DynamicLoader&);
  DynamicLoader& operator=(const DynamicLoader&);

  int	loadGui(const std::string &);

  IGui	*getGui() const;
};

#endif
