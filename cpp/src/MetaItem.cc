#include "MetaItem.h"

MetaItem::MetaItem(std::string name, int sellIn, int quality) : Item(name, sellIn, quality)
{
    setQuality(quality);
    setSellIn(sellIn);
}
