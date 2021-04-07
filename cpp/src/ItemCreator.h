#ifndef ITEMCREATOR
#define ITEMCREATOR

#include <string>
#include <vector>

#include "macros.h"
#include "MetaItem.h"
#include "AgedBrieItem.h"
#include "BackstagePassesItem.h"
#include "CommonItem.h"
#include "ConjuredItem.h"
#include "SulfurasItem.h"

class ItemCreator{
private:
  // vector holding strings for identification of item category.
  // defined in "macros.h"
  const std::vector<std::string> _v_str_category_names {
      AGEDBRIE_STRID, BACKSTAGEPASSES_STRID, CONJURED_STRID, SULFURAS_STRID};

  itemtype findTypeFromName(const std::string& name );

public:
  ItemCreator(void);
  MetaItem* ItemCreate( const std::string& name, const int sellIn, const int quality, itemtype iType = type_unspecified );
};

#endif
