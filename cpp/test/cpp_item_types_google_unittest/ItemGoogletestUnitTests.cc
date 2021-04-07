#include <gtest/gtest.h>

#include <tuple>  // tuple is used for input of testparameter

// headers for tested Item classes:
#include "MetaItem.h"
#include "AgedBrieItem.h"
#include "BackstagePassesItem.h"
#include "CommonItem.h"
#include "ConjuredItem.h"
#include "SulfurasItem.h"

//Class for Testsuite able to test all item types:
class ItemTestSuite :
  public :: testing::TestWithParam <
    std::tuple <
      std::string,            // testname
      itemtype,               // type
      std::vector < int >,    // start sellIns
      std::vector < int >,    // start qualities
      std::vector < int >,    // expected sellIns
      std::vector < int >     // expected qualities
    >
  > {};

TEST_P(ItemTestSuite, CheckItemIntegrity) {

  // get Parameters for testing.
  // make sure the vectors have the same length each!
  const std::string name                = std::get<0>(GetParam());
  const itemtype it                     = std::get<1>(GetParam());
  const std::vector<int> startSellIns   = std::get<2>(GetParam());
  const std::vector<int> startQualities = std::get<3>(GetParam());
  const std::vector<int> expecSellIns   = std::get<4>(GetParam());
  const std::vector<int> expecQualities = std::get<5>(GetParam());

  MetaItem* item;
  int sellIn;
  int quality;

  // check for correct Testinstantiation:
  std::string assert_expl {"BAD TESTINSTANTIATION: parameter vectors do not match in length!"};
  ASSERT_EQ( startSellIns.size(), startQualities.size() ) << assert_expl ;
  ASSERT_EQ( startQualities.size(), expecQualities.size() ) << assert_expl ;
  ASSERT_EQ( startSellIns.size(), expecSellIns.size() ) << assert_expl ;

  // run Tests for each given element of start and expec vector.
  for ( int i = 0; i < startSellIns.size(); i++ ){

    sellIn = startSellIns.at(i);
    quality = startQualities.at(i);

    // Instantiate ItemObject for testing accroding to itemtype parameter.
    switch (it) {
      case type_agedbrie: item = new AgedBrieItem( name, sellIn, quality );
                          break;
      case type_backstagepasses:
                          item = new BackstagePassesItem( name, sellIn, quality );
                          break;
      case type_common:   item = new CommonItem( name, sellIn, quality );
                          break;
      case type_conjured: item = new ConjuredItem( name, sellIn, quality );
                          break;
      case type_sulfuras: item = new SulfurasItem( name, sellIn, quality);
                          break;
      default : item = new CommonItem( name, sellIn, quality ); // this should not happen...
    }

    item->updateQuality();

    // make transparent what happend during updateQuality() call:
    std::stringstream s_explanation;
    s_explanation << "[" << name << ", " << sellIn << ", "<< quality <<
    "] --updateQuality()--> ["
    << item->getName() << ", " << item->getSellIn() << ", "<< item->getQuality() << "]" ;

    // TESTING:
    // check for correct TYPE in Item object:
    EXPECT_EQ(item->getType(), it) << "Item::getType() does not provide the correct type." << std::endl;

    // check for correct NAME in Item object:
    EXPECT_EQ(item->getName(), name) <<
      "Item::getName() does not provide the correct name."<< std::endl << s_explanation.str() << std::endl;

    // check for correct SELLIN value in Item object after Item specific updateQuality() call:
    EXPECT_EQ(item->getSellIn(), expecSellIns.at(i)) <<
      "After Item::updateQuality, Item::getSellIn() value [" << item->getSellIn() << "] is not equal to expected [" << expecSellIns.at(i) << "]." << std::endl << s_explanation.str() << std::endl;

    // check for correct QUALITY value in Item object after Item specific updateQuality() call:
    EXPECT_EQ(item->getQuality(), expecQualities.at(i)) <<
      "After Item::updateQuality(), Item::getQuality() value [" << item->getQuality() << "] is not equal to expected [" << expecQualities.at(i) << "]." << std::endl << s_explanation.str() << std::endl;

  }
}

//
// Instantiate the specific test cases for each itemtype:
//
//AGED BRIE
INSTANTIATE_TEST_CASE_P(
  AgedBrieItemTest,
  ItemTestSuite,
  ::testing::Values(
    std::make_tuple(
      std::string { "Aged Brie Testitem" },
      itemtype { type_agedbrie },
      std::vector< int > { 0,  0,  1, 1},     //start sellIns
      std::vector< int > {40, 49, 50, 0},     //start qualities
      std::vector< int > { 0,  0,  0, 0},     //expect sellIns
      std::vector< int > {42, 50, 50, 1}      //expect qualities
    )
  )
);

//BACKSTAGE PASSES
INSTANTIATE_TEST_CASE_P(
  BackstagePassesItemTest,
  ItemTestSuite,
  ::testing::Values(
    std::make_tuple(
      std::string { "Backstage Passes Testitem" },
      itemtype { type_backstagepasses },
      std::vector< int > { 0,  1,  5,  6, 10, 11},  //start sellIns
      std::vector< int > {40, 40, 47, 47, 47, 40},  //start qualities
      std::vector< int > { 0,  0,  4,  5,  9, 10},  //expect sellIns
      std::vector< int > { 0, 43, 50, 49, 49, 41}   //expect qualities
    )
  )
);

//COMMON
INSTANTIATE_TEST_CASE_P(
  CommonItemTest,
  ItemTestSuite,
  ::testing::Values(
    std::make_tuple(
      std::string { "Miscellaneous Testitem" },
      itemtype { type_common },
      std::vector< int > {0, 0, 0, 1},   //start sellIns
      std::vector< int > {0, 3, 1, 3},   //start qualities
      std::vector< int > {0, 0, 0, 0},   //expect sellIns
      std::vector< int > {0, 1, 0, 2}    //expect qualities
    )
  )
);

//CONJURED
INSTANTIATE_TEST_CASE_P(
  ConjuredItemTest,
  ItemTestSuite,
  ::testing::Values(
    std::make_tuple(
      std::string { "Conjured Testitem" },
      itemtype { type_conjured },
      std::vector< int > {0, 0, 0, 1},   //start sellIns
      std::vector< int > {0, 3, 5, 3},   //start qualities
      std::vector< int > {0, 0, 0, 0},   //expect sellIns
      std::vector< int > {0, 0, 1, 1}    //expect qualities
    )
  )
);

//SULFURAS
INSTANTIATE_TEST_CASE_P(
  SulfurasItemTest,
  ItemTestSuite,
  ::testing::Values(
    std::make_tuple(
      std::string { "Sulfuras Testitem" },
      itemtype { type_sulfuras },
      std::vector< int > { 0,  1, 50,  1},   //start sellIns
      std::vector< int > { 0,  3, 50, 80},   //start qualities
      std::vector< int > { 0,  1, 50,  1},   //expect sellIns
      std::vector< int > {80, 80, 80, 80}    //expect qualities
    )
  )
);
