#ifndef METAITEM
#define METAITEM

#include <string>
#include <vector>
#include "macros.h"
#include "Item.h"

//Library Classes
class MetaItem : public Item
{
protected:
  virtual void setQuality( const int quality_value ){ quality = quality_value; }
  virtual void setSellIn( const int sellIn_value ){ sellIn = sellIn_value; }

public:
  MetaItem(std::string name, int sellIn, int quality);
  virtual void updateQuality(void) = 0;

};

#endif
