#ifndef METAITEM
#define METAITEM

#include <string>
#include <vector>
#include "macros.h"
#include "Item.h"

//Library Classes
class MetaItem : public Item
{

public:
  MetaItem(std::string name, int sellIn, int quality);
  virtual void updateQuality(void) = 0;

};

#endif
