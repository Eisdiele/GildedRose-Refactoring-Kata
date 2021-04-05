#include "MetaItem.h"

MetaItem::MetaItem(std::string name, int sellIn, int quality) : Item(name, sellIn, quality)
{
    setQuality(quality);
    setSellIn(sellIn);
}

void MetaItem::setQuality( const int quality_value )
{
    if (( quality_value <= MAX_QUALITY ) && ( quality_value >= MIN_QUALITY ))
    {
        quality = quality_value;
    } else {
        if ( quality_value < MIN_QUALITY ) {
            quality = MIN_QUALITY;
        }
        if ( quality_value > MAX_QUALITY ) {
            quality = MAX_QUALITY;
        }
    }
}

void MetaItem::setSellIn( const int sellIn_value )
{
  if ( sellIn_value >= MIN_SELLIN ) {
      sellIn = sellIn_value;
  } else {
      sellIn = MIN_SELLIN;
  }

}
