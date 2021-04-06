#include "CommonItem.h"

CommonItem::CommonItem(const std::string& name, int sellIn, int quality) : MetaItem(name, sellIn, quality)
{
}

void CommonItem::updateQuality(void){

  // Just pasted GildedRose::updateQuality() below:
  //
  // TEST: Have a look at "Certification4Restructure" tests
  // and check if everything works as before.
  //
  // Condensed original GildedRose::qualityUpdate() to
  //       --"any"--
  // Concerning code only.
  //
  // Test: check!

  if (quality > 0)
  {
      setQuality( quality - 1 );
  }

  if (sellIn > 0)
  {
      setSellIn();
  }

  if (sellIn < 0)
  {
      if (quality > 0)
      {
          setQuality( quality - 1 );
      }
  }

}
