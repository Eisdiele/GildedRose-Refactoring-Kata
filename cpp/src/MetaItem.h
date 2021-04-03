#ifndef METAITEM
#define METAITEM

#include <string>
#include "Item.h"

class MetaItem : public Item
{

public:
  MetaItem(std::string name, int sellIn, int quality);
  virtual void updateQuality(void);

};

#endif
