#ifndef CONJUREDITEM
#define CONJUREDITEM

#include "CommonItem.h"


class ConjuredItem : public CommonItem {

protected:
  virtual int getQStep() override { return (2 * QUALITY_STEP); };

public:
  ConjuredItem(const std::string& name, int sellIn, int quality);
  itemtype getType(void) override { return type_conjured; }

};

#endif
