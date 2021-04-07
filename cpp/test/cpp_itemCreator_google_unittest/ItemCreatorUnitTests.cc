#include <gtest/gtest.h>

#include <tuple> // tuple is used for input of testparameters

//headers for tested ItemCreator:
#include "ItemCreator.h"

class ItemCreatorTestSuite :
  public :: testing::TestWithParam <
    std::tuple <
      std::vector< itemtype >,     // itemtype input for object declaration
      std::vector< std::string >,  // name
      std::vector< itemtype >      // itemtype expected from object Item::getType() method.
    >
  > {
  public:
    MetaItem* item;
    ItemCreator iC;
    std::string instan_expl {"BAD TESTINSTANTIATION: unequal length of parameter vectors."};
    std::string type_expl {"Types: 0->[Aged Brie], 1->[Backstage passes], 2->[Common], 3->[Conjured], 4->[Sulfuras], 5->[Unspecified]"};
  };


TEST_P(ItemCreatorTestSuite, ItemCreateTest) {

  const std::vector< itemtype > v_it_input    = std::get<0>(GetParam());
  const std::vector< std::string > v_name     = std::get<1>(GetParam());
  const std::vector< itemtype > v_it_expected = std::get<2>(GetParam());

  // check for correct Testinstantiation:
  ASSERT_EQ( v_it_input.size(), v_it_expected.size() ) << instan_expl ;
  ASSERT_EQ( v_it_input.size(), v_name.size() ) << instan_expl ;

  // For each provided sample test for correct type creation.
  for (int i = 0; i < v_it_input.size(); i++){

    // create Item object via ItemCreate() method.
    item = iC.ItemCreate( v_name.at(i), 1, 1, v_it_input.at(i) );

    // Test if type is as expected.
    EXPECT_EQ( item->getType(), v_it_expected.at(i) )
      << "Item object declared by ItemCreator::ItemCreate does not provide expected type ["
      << v_it_input.at(i) << "] by Item::getType()"
      << item->getType() << "."
      << std::endl << type_expl << std::endl;

  }

}

// Test for correct itemtype in Item objects created by passing type explicitly.
INSTANTIATE_TEST_CASE_P(
  ItemCreatorFromTYPETest,
  ItemCreatorTestSuite,
  ::testing::Values(
    std::make_tuple(
      std::vector< itemtype > { type_agedbrie,
                              type_backstagepasses,
                              type_common,
                              type_conjured,
                              type_sulfuras },
      std::vector< std::string > {"AB Item",
                                  "BP Item",
                                  "CM Item",
                                  "CJ Item",
                                  "SL Item"
                                },
      std::vector< itemtype > { type_agedbrie,
                              type_backstagepasses,
                              type_common,
                              type_conjured,
                              type_sulfuras }
    )
  )
);

// Test for correct itemtype in Item objects created by passing no itemtype,
// but providing type information in name.
INSTANTIATE_TEST_CASE_P(
  ItemCreatorFromNAMETest,
  ItemCreatorTestSuite,
  ::testing::Values(
    std::make_tuple(
      std::vector< itemtype > { type_unspecified,
                                type_unspecified,
                                type_unspecified,
                                type_unspecified,
                                type_unspecified },
      std::vector< std::string > { "Aged Brie Item",
                                   "Backstage passes Item",
                                   "Common Item",
                                   "Conjured Item",
                                   "Sulfuras Item" },
      std::vector< itemtype > { type_agedbrie,
                                type_backstagepasses,
                                type_common,
                                type_conjured,
                                type_sulfuras }
    )
  )
);
