#include "BackstagePassesItem.h"

BackstagePassesItem::BackstagePassesItem(const std::string& name, int sellIn, int quality) : MetaItem(name, sellIn, quality)
{
}

void BackstagePassesItem::updateQuality(void){

  int i_add_quality = getQStep();

  if (sellIn < 11)
  {
    i_add_quality += getQStep();
  }

  if (sellIn < 6)
  {
    i_add_quality += getQStep();
  }

  if (sellIn == 0)
  {
    i_add_quality = -1 * quality;
  }

  setQuality( quality + i_add_quality );
  setSellIn();

}
