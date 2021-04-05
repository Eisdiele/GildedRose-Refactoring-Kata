#include "GildedRose.h"

GildedRose::GildedRose(std::vector<Item> & items) : items(items)
{
    createMetaItemsFromItems();
}

GildedRose::~GildedRose(void)
{
    for (int i = 0; i < _v_meta_items.size(); i++)
    {
      delete _v_meta_items[i];
    }
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
        _v_meta_items.push_back( _ItmCrt.ItemCreate(items.at(i).name,
                                                items.at(i).sellIn,
                                                items.at(i).quality) );
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
