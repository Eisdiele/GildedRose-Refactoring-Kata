#ifndef SULFURASITEM
#define SULFURASITEM

#include "macros.h"
#include "MetaItem.h"

class SulfurasItem : public MetaItem {

protected:
  void setQuality( const int quality_value ) override;

public:
  SulfurasItem(const std::string& name, int sellIn, int quality);
  void updateQuality(void) override;
  itemtype getType(void) override { return type_sulfuras; }
};

#endif
