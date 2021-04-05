#ifndef GILDEDROSE
#define GILDEDROSE

#include <vector>
#include "MetaItem.h"
#include "ItemCreator.h"

class GildedRose
{
private:
    // _v_meta_items vector holds pointers to objects of class "Meta_item".
    // By this means an object oriented approach is implemented.
    std::vector<MetaItem*> _v_meta_items;
    ItemCreator _ItmCrt;

public:

    std::vector<Item> & items;

    GildedRose(std::vector<Item> & items );
    ~GildedRose(void);

    void updateQuality(void);
    void createMetaItemsFromItems(void);
    void updateItems(void);
};

#endif
