#ifndef COMMONITEM
#define COMMONITEM

#include "MetaItem.h"

class CommonItem : public MetaItem {
  
protected:
  virtual int get_uQ_factor(){ return 1; };

public:
  CommonItem(const std::string& name, int sellIn, int quality);
  void updateQuality(void) override;
};

#endif
