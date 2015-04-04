#ifndef DYNAMICLOADER_HPP
# define DYNAMICLOADER_HPP

#include <string>

class DynamicLoader
{
private:
  void	*_handle;

public:
  DynamicLoader();
  ~DynamicLoader();
  DynamicLoader(const DynamicLoader&);
  DynamicLoader& operator=(const DynamicLoader&);

  int	loadGui(const std::string &);
};

#endif
