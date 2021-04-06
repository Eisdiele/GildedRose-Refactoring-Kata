#include "SulfurasItem.h"

SulfurasItem::SulfurasItem(const std::string& name, int sellIn, int quality) : MetaItem(name, sellIn, quality)
{
}

void SulfurasItem::updateQuality(void){
  //checks for correct quality value.
  setQuality( 0 );
}

void SulfurasItem::setQuality( const int quality_value ){
  //checks for correct sulfuras quality value and sets it if not correct:
  if ( quality != FIX_LEGENDARY_QUALITY )
  {
    quality = FIX_LEGENDARY_QUALITY;
  }
}
