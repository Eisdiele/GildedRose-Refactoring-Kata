set(SRC_LIB_NAME src)
add_library(${SRC_LIB_NAME})
target_sources(${SRC_LIB_NAME} PRIVATE  GildedRose.cc
                                        ItemCreator.cc
                                        MetaItem.cc
                                        AgedBrieItem.cc
                                        BackstagePassesItem.cc
                                        CommonItem.cc
                                        ConjuredItem.cc
                                        SulfurasItem.cc
                                        macros.h
                                        Item.h)
target_include_directories(${SRC_LIB_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
