#include "CommonItem.h"

CommonItem::CommonItem(const std::string& name, int sellIn, int quality) : MetaItem(name, sellIn, quality)
{
}

void CommonItem::updateQuality(void){

  // Just pasted GildedRose::updateQuality() below:
  //
  // TEST: Have a look at "Certification4Restructure" tests
  // and check if everything works as before.

  if (name != "Aged Brie" && name != "Backstage passes to a TAFKAL80ETC concert")
  {
      if (quality > 0)
      {
          if (name != "Sulfuras, Hand of Ragnaros")
          {
              quality = quality - 1;
          }
      }
  }
  else
  {
      if (quality < 50)
      {
          quality = quality + 1;

          if (name == "Backstage passes to a TAFKAL80ETC concert")
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
  }

  if ((name != "Sulfuras, Hand of Ragnaros") && (sellIn > 0))
  {
      sellIn = sellIn - 1;
  }

  if (sellIn < 0)
  {
      if (name != "Aged Brie")
      {
          if (name != "Backstage passes to a TAFKAL80ETC concert")
          {
              if (quality > 0)
              {
                  if (name != "Sulfuras, Hand of Ragnaros")
                  {
                      quality = quality - 1;
                  }
              }
          }
          else
          {
              quality = quality - quality;
          }
      }
      else
      {
          if (quality < 50)
          {
              quality = quality + 1;
          }
      }
  }

}
