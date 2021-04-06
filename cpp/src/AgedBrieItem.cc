#include "AgedBrieItem.h"

AgedBrieItem::AgedBrieItem(const std::string& name, int sellIn, int quality) : MetaItem(name, sellIn, quality)
{
}

void AgedBrieItem::updateQuality(void){

  int act_step = getQStep();

  // double quality increase if sell by date has passed:
  if ( sellIn == MIN_SELLIN ){
    act_step = act_step * 2;
  }

  setQuality( quality + act_step );
  setSellIn();

}
