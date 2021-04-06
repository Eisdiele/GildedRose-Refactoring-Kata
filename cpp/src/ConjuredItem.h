#ifndef CONJUREDITEM
#define CONJUREDITEM

#include "CommonItem.h"


class ConjuredItem : public CommonItem {
  
protected:
  virtual int get_uQ_factor() override { return 2; };

public:
  ConjuredItem(const std::string& name, int sellIn, int quality);

};

#endif
