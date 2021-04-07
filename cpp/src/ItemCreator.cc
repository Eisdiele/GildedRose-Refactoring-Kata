#include "ItemCreator.h"

ItemCreator::ItemCreator(void){}

// Factory method
// creates and returns objects of different types according to iType
// or if type_unspecified searches "name" parameter for keywords.
MetaItem* ItemCreator::ItemCreate( const std::string& name, const int sellIn, const int quality, itemtype iType ){

    if (iType == type_unspecified){
      iType = this->findTypeFromName( name );
    }

    switch (iType) {
      case type_agedbrie :          return new AgedBrieItem( name, sellIn, quality );
      case type_backstagepasses :   return new BackstagePassesItem( name, sellIn, quality );
      case type_common :            return new CommonItem( name, sellIn, quality );
      case type_conjured :          return new ConjuredItem( name, sellIn, quality );
      case type_sulfuras :          return new SulfurasItem( name, sellIn, quality );
      default : return new CommonItem( name, sellIn, quality ); // this should not happen!
    }
}

// Method to find identifier number from "name" parameter.
itemtype ItemCreator::findTypeFromName( const std::string& name )
{
    // CommonItem is the standard and therefor assigns to size of vector.
    // This is due to switch statement used in ItemCreator::ItemCreate().
    int i_category_idnum = _v_str_category_names.size();
    std::size_t found_cat_idnum;

    for (int i = 0; i < _v_str_category_names.size(); i++)
    {
        // std::string.find() finds substring in string.
        // here the name is searched for predefined identifier keywords.
        found_cat_idnum = name.find(_v_str_category_names[i]);

        // if found is not std::string::npos there was a match!
        // save it and break.
        if (found_cat_idnum != std::string::npos)
        {
            i_category_idnum = i;
            break;
        }
    }

    // find itemtype from position of matching keyword in vector
    // return found itemtype:
    switch (i_category_idnum) {
      case 0 : return type_agedbrie;
      case 1 : return type_backstagepasses;
      case 2 : return type_conjured;
      case 3 : return type_sulfuras;
      default : return type_common;
    }

}
