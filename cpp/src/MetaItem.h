#ifndef METAITEM
#define METAITEM

#include <string>
#include <vector>
#include "macros.h"
#include "Item.h"

enum itemtype {
  type_agedbrie, type_backstagepasses, type_common, type_conjured, type_sulfuras, type_unspecified
};

//Library Classes
class MetaItem : public Item
{
protected:

  virtual int getQStep() { return QUALITY_STEP; }
  virtual void setQuality( const int quality_value );
  virtual void setSellIn( void );

public:

  MetaItem(std::string name, int sellIn, int quality);
  virtual void updateQuality(void) = 0;
  virtual itemtype getType(void){return type_unspecified;}
  virtual std::string getName(void){return name;}
  virtual int getSellIn(void){return sellIn;}
  virtual int getQuality(void){return quality;}

};

#endif
