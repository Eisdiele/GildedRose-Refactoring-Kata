#include "GildedRose.h"

GildedRose::GildedRose(std::vector<Item> & items) //: items(items)
{
    createMetaItemsFromItems(items); // make more elegant!
}

GildedRose::GildedRose(std::vector<MetaItem*> & items) : _v_meta_items(items)
{}

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
}

void GildedRose::createMetaItemsFromItems(const std::vector<Item> & items)
{
    for( int i = 0; i < items.size(); i++){
        _v_meta_items.push_back( _ItmCrt.ItemCreate(items.at(i).name,
                                                items.at(i).sellIn,
                                                items.at(i).quality) );
    }
}

std::vector<Item> GildedRose::getItemInventory(void)
{

  std::vector<Item> inventoryItems;
  for (int i = 0; i < _v_meta_items.size(); i++)
  {
    inventoryItems.push_back(Item(_v_meta_items.at(i)->getName(),
                                  _v_meta_items.at(i)->getSellIn(),
                                  _v_meta_items.at(i)->getQuality()));
  }
  return inventoryItems;

}
