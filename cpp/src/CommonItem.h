#ifndef COMMONITEM
#define COMMONITEM

#include "MetaItem.h"

class CommonItem : public MetaItem {

public:
  CommonItem(const std::string& name, int sellIn, int quality);
  void updateQuality(void) override;
  itemtype getType(void) override { return type_common; }
};

#endif
