#include "DynamicLoader.hpp"

DynamicLoader::DynamicLoader()
{
}

DynamicLoader::~DynamicLoader()
{
}

DynamicLoader::DynamicLoader(const DynamicLoader& rhs __attribute__((unused)))
{
}

DynamicLoader&		DynamicLoader::operator=(const DynamicLoader& rhs)
{
  if (this != &rhs)
    {
    }
  return *this;
}

int			DynamicLoader::loadGui()
{
  return 0;
}
