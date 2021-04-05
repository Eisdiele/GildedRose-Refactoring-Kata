#ifndef METAITEM
#define METAITEM

#include <string>
#include <vector>
#include "macros.h"
#include "Item.h"

//Library Classes
class MetaItem : public Item
{
private:

  //const?
  int categoryEnum(std::string & name);

public:
  MetaItem(std::string name, int sellIn, int quality);
  MetaItem* Create(std::string & name, const int sellIn, const int quality);
  virtual void updateQuality(void);

};

#endif
