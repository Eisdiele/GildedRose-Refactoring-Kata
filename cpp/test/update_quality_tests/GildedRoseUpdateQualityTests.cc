// Include header files for test frameworks
#include <gtest/gtest.h>
#include <ApprovalTests.hpp>

// Include header for tuple usage
#include <tuple>

// Include code to be tested
#include "GildedRose.h"

//Class for Testsuite making use of parameterized Testing
class UpdateQualityTestSuite :
    public :: testing::TestWithParam <
        std::tuple <
            std::vector < std::string >,
            std::vector < int >,
            std::vector < int >
        >
    > {};

//"operator" is used for human readable output of googletest-tests
std::ostream& operator<<(std::ostream& os, const Item& obj)
{
    return os
        << "name: " << obj.name
        << ", sellIn: " << obj.sellIn
        << ", quality: " << obj.quality;
}

//Parameterized Test for items in GildedRoses system
TEST_P(UpdateQualityTestSuite, UpdateQualityVerify) {

    const std::vector<std::string> names = std::get<0>(GetParam());
    const std::vector<int> sellIns       = std::get<1>(GetParam());
    const std::vector<int> qualities     = std::get<2>(GetParam());

    auto f = [](std::string name, int sellIn, int quality) {
        std::vector<Item> items = {Item(name, sellIn, quality)};
        GildedRose app(items);
        app.updateQuality();
        items = app.getItemInventory();
        return items[0];
    };

    ApprovalTests::CombinationApprovals::verifyAllCombinations(
            f,
            names, sellIns, qualities);

}

//=============================================================================
// AGED BRIE TEST
// Tests for correct behaviour of aged brie items in GildedRose system.
//
INSTANTIATE_TEST_CASE_P(
    AgedBrieTests,
    UpdateQualityTestSuite,
    ::testing::Values(
      std::make_tuple(
        std::vector<std::string> { "Aged Brie", "Aged Brie Cheese" },
        std::vector<int> { 0, 1 },       //sellIns
        std::vector<int> { 40, 49, 50 }  //qualities
      )
    )
);

//=============================================================================
// BACKSTAGE PASSES TEST
// Tests for correct behaviour of backstage pass items in GildedRose system.
//
INSTANTIATE_TEST_CASE_P(
    BackstagePassesTests,
    UpdateQualityTestSuite,
    ::testing::Values(
      std::make_tuple(
        std::vector<std::string> { "Backstage passes",
                                  "Backstage passes to a TAFKAL80ETC concert" },
        std::vector<int> { 0, 5, 10, 11 },  //sellIns
        std::vector<int> { 0, 48, 49, 50 }  //qualities
      )
    )
);

//=============================================================================
// COMMON ITEM TEST
// Tests for correct behaviour of common items in GildedRose system.
//
INSTANTIATE_TEST_CASE_P(
    CommonItemTests,
    UpdateQualityTestSuite,
    ::testing::Values(
      std::make_tuple(
        std::vector<std::string> { "Bread", "Water" },
        std::vector<int> { 0, 1 },     //sellIns
        std::vector<int> { 0, 1, 30 }  //qualities
      )
    )
);

//=============================================================================
// CONJURED TEST
// Tests for correct behaviour of conjured items in GildedRose system.
//
INSTANTIATE_TEST_CASE_P(
    ConjuredTests,
    UpdateQualityTestSuite,
    ::testing::Values(
      std::make_tuple(
        std::vector<std::string> { "Conjured", "Conjured Ring" },
        std::vector<int> { 0, 1 },           //sellIns
        std::vector<int> { 0, 1, 2, 3, 10 }  //qualities
      )
    )
);


//=============================================================================
// SULFURAS TEST
// Tests for correct behaviour of sulfuras items in GildedRose system.
//
INSTANTIATE_TEST_CASE_P(
    SulfurasTests,
    UpdateQualityTestSuite,
    ::testing::Values(
      std::make_tuple(
        std::vector<std::string> { "Sulfuras", "Sulfuras, Hand of Ragnaros" },
        std::vector<int> { 0, 1 },      //sellIns
        std::vector<int> { 0, 50, 80 }  //qualities
      )
    )
);
