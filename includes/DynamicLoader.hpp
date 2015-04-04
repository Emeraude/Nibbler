#ifndef DYNAMICLOADER_HPP
# define DYNAMICLOADER_HPP

class DynamicLoader
{
public:
  DynamicLoader();
  ~DynamicLoader();
  DynamicLoader(const DynamicLoader&);
  DynamicLoader& operator=(const DynamicLoader&);

  int	loadGui();
};

#endif
