#include "AgedBrieItem.h"

AgedBrieItem::AgedBrieItem(const std::string& name, int sellIn, int quality) : MetaItem(name, sellIn, quality)
{
}

void AgedBrieItem::updateQuality(void){

  // Just pasted GildedRose::updateQuality() below:
  //
  // TEST: Have a look at "Certification4Restructure" tests
  // and check if everything works as before.
  //
  // Condensed original GildedRose::qualityUpdate() to
  //       --"Aged Brie"--
  // Concerning code only.
  //
  // Test: check!

  if (quality < 50)
  {
      setQuality( quality + 1 );
  }

  if (sellIn > 0)
  {
      setSellIn( sellIn - 1 );
  }

  if (sellIn < 0)
  {
      if (quality < 50)
      {
          setQuality( quality + 1 );
      }
  }

}
