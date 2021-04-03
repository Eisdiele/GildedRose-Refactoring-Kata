#include "MetaItem.h"

MetaItem::MetaItem(std::string name, int sellIn, int quality) : Item(name, sellIn, quality)
{}

void MetaItem::updateQuality(void){

  // Just pasted GildedRose::updateQuality() below:
  //
  // TEST: Have a look at "Certification4Restructure" tests
  // and check if everything works as before.

  if (this->name != "Aged Brie" && this->name != "Backstage passes to a TAFKAL80ETC concert")
  {
      if (this->quality > 0)
      {
          if (this->name != "Sulfuras, Hand of Ragnaros")
          {
              this->quality = this->quality - 1;
          }
      }
  }
  else
  {
      if (this->quality < 50)
      {
          this->quality = this->quality + 1;

          if (this->name == "Backstage passes to a TAFKAL80ETC concert")
          {
              if (this->sellIn < 11)
              {
                  if (this->quality < 50)
                  {
                      this->quality = this->quality + 1;
                  }
              }

              if (this->sellIn < 6)
              {
                  if (this->quality < 50)
                  {
                      this->quality = this->quality + 1;
                  }
              }
          }
      }
  }

  if ((this->name != "Sulfuras, Hand of Ragnaros") && (this->sellIn > 0))
  {
      this->sellIn = this->sellIn - 1;
  }

  if (this->sellIn < 0)
  {
      if (this->name != "Aged Brie")
      {
          if (this->name != "Backstage passes to a TAFKAL80ETC concert")
          {
              if (this->quality > 0)
              {
                  if (this->name != "Sulfuras, Hand of Ragnaros")
                  {
                      this->quality = this->quality - 1;
                  }
              }
          }
          else
          {
              this->quality = this->quality - this->quality;
          }
      }
      else
      {
          if (this->quality < 50)
          {
              this->quality = this->quality + 1;
          }
      }
  }

}
