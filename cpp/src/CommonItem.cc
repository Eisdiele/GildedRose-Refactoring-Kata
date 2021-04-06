#include "CommonItem.h"

CommonItem::CommonItem(const std::string& name, int sellIn, int quality) : MetaItem(name, sellIn, quality)
{
}

void CommonItem::updateQuality(void){

  int i_degrade_quality = -1 * getQStep();

  if (sellIn == 0)
  {
    i_degrade_quality *= 2;
  }

  setQuality( quality + i_degrade_quality );
  setSellIn();

}
