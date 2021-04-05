#include "ItemCreator.h"

ItemCreator::ItemCreator(void){}

// Factory method
// creates and returns objects of different types according to "name" parameter.
MetaItem* ItemCreator::ItemCreate(const std::string& name, const int sellIn, const int quality){

    int category_num = this->categoryEnum( name );

    switch (category_num) {
      case 0 :  return new AgedBrieItem( name, sellIn, quality );
      case 1 :  return new BackstagePassesItem( name, sellIn, quality );
      case 2 :  return new ConjuredItem( name, sellIn, quality );
      case 3 :  return new SulfurasItem( name, sellIn, quality );
      default : return new CommonItem( name, sellIn, quality ); // == case 4
    }
}

// Method to find identifier number from "name" parameter.
int ItemCreator::categoryEnum(const std::string& name )
{
    // CommonItem is the standard and therefor assigns to size of vector.
    // This is due to switch statement used in ItemCreator::ItemCreate().
    int i_category_idnum = _v_str_category_names.size();
    std::size_t found_cat_idnum;

    for (int i = 0; i < _v_str_category_names.size(); i++)
    {
        // std::string.find() finds substring in string.
        // here the name is searched for predefined identifiers.
        found_cat_idnum = name.find(_v_str_category_names[i]);

        // if found is not std::string::npos there was a match!
        // save it and break, then return value.
        if (found_cat_idnum != std::string::npos)
        {
            i_category_idnum = i;
            break;
        }
    }

    return i_category_idnum;
}
