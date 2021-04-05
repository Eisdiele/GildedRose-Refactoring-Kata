#include "BackstagePassesItem.h"

BackstagePassesItem::BackstagePassesItem(const std::string& name, int sellIn, int quality) : MetaItem(name, sellIn, quality)
{
}

void BackstagePassesItem::updateQuality(void){

  // Just pasted GildedRose::updateQuality() below:
  //
  // TEST: Have a look at "Certification4Restructure" tests
  // and check if everything works as before.
  //
  // Condensed original GildedRose::qualityUpdate() to
  //   --"Backstage passes to a TAFKAL80ETC concert"--
  // Concerning code only.
  //
  // Test: check!


  if (quality < 50)
  {
      quality = quality + 1;

      if (true)
      {
          if (sellIn < 11)
          {
              if (quality < 50)
              {
                  quality = quality + 1;
              }
          }

          if (sellIn < 6)
          {
              if (quality < 50)
              {
                  quality = quality + 1;
              }
          }
      }
  }

  if ((true) && (sellIn > 0))
  {
      sellIn = sellIn - 1;
  }

  if (sellIn < 0)
  {
      quality = quality - quality;
  }

}
