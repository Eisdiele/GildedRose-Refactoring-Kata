#include "GildedRose.h"

GildedRose::GildedRose(std::vector<Item> & items) : items(items)
{
    createMetaItemsFromItems();
}

void GildedRose::updateQuality(void)
{
    for (int i = 0; i < _v_meta_items.size(); i++)
    {
        _v_meta_items[i]->updateQuality();
    }

    updateItems();

}

void GildedRose::createMetaItemsFromItems(void)
{
    for( int i = 0; i < items.size(); i++){
        _v_meta_items.push_back(new CommonItem(items[i].name, items[i].sellIn, items[i].quality));
    }
}

void GildedRose::updateItems(void)
{
    if ( items.size() == _v_meta_items.size() )
    {
        for( int i = 0; i < items.size(); i++){
            items[i].sellIn = _v_meta_items[i]->sellIn;
            items[i].quality = _v_meta_items[i]->quality;
        }
    }

}
