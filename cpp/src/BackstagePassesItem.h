#ifndef BACKSTAGEPASSESITEM
#define BACKSTAGEPASSESITEM

#include "MetaItem.h"

class BackstagePassesItem : public MetaItem {

public:
  BackstagePassesItem(const std::string& name, int sellIn, int quality);
  void updateQuality(void) override;

};

#endif
