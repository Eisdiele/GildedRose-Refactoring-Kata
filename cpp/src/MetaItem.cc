#include "MetaItem.h"

MetaItem::MetaItem(std::string name, int sellIn, int quality) : Item(name, sellIn, quality)
{
    setQuality(quality);
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

void MetaItem::setSellIn( void )
{
  if ( sellIn > MIN_SELLIN ) {
      sellIn = sellIn - SELLIN_STEP;
  }
  if (sellIn < MIN_SELLIN) {
      sellIn = MIN_SELLIN;
  }

}
