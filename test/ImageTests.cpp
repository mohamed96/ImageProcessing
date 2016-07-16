//
// Created by mohamed on 15/07/16.
//

#include "gtest/gtest.h"
#include "../Image.h"

TEST(ImageTests, DefaultConstructor){
    Image img;
    ASSERT_EQ(3, img.width);
    ASSERT_EQ(3, img.height);
}


