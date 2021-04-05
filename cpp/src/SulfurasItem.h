#ifndef SULFURASITEM
#define SULFURASITEM

#include "MetaItem.h"

class SulfurasItem : public MetaItem {

public:
  SulfurasItem(const std::string& name, int sellIn, int quality);
  void updateQuality(void) override;
};

#endif
