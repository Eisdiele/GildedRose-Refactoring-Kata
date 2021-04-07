#include "MetaItem.h"

MetaItem::MetaItem(std::string name, int sellIn, int quality) : Item(name, sellIn, quality)
{
    // Make sure valid quality and sellIn values are going to be stored only.
    setQuality( quality );
    setSellIn( false ); // call setSellIn(), dont do a step in time but check for valid sellIn.
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

void MetaItem::setSellIn( const bool do_step )
{
  if (( sellIn > MIN_SELLIN ) && do_step ) {
      sellIn = sellIn - SELLIN_STEP;
  }
  if (sellIn < MIN_SELLIN) {
      sellIn = MIN_SELLIN;
  }

}
