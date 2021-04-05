#ifndef AGEDBRIEITEM
#define AGEDBRIEITEM

#include "MetaItem.h"

class AgedBrieItem : public MetaItem {

public:
  AgedBrieItem(const std::string& name, int sellIn, int quality);
  virtual void updateQuality(void){MetaItem::updateQuality();}
};

#endif
