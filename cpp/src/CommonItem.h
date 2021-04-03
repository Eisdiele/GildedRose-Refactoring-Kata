#ifndef COMMONITEM
#define COMMONITEM

#include "MetaItem.h"

class CommonItem : public MetaItem {

public:
  CommonItem(const std::string& name, int sellIn, int quality) : MetaItem(name, sellIn, quality)
  {
  };

};

#endif
