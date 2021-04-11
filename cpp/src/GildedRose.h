#ifndef GILDEDROSE
#define GILDEDROSE

#include <vector>
#include "Item.h"
#include "MetaItem.h"
#include "ItemCreator.h"

class GildedRose
{
private:
    // _v_meta_items vector holds pointers to objects of items derived from class "MetaItem":
    std::vector<MetaItem*> _v_meta_items;
    // _ItmCrt is the object factory for item of different types:
    ItemCreator _ItmCrt;
    void createMetaItemsFromItems(const std::vector<Item> & items);

public:

    GildedRose(std::vector<Item> & items );
    GildedRose(std::vector<MetaItem*> & items);
    ~GildedRose(void);

    void updateQuality(void);
    std::vector<MetaItem*> getInventory(void){return _v_meta_items;}
    std::vector<Item> getItemInventory(void);

};

#endif
