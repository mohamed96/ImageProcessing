//
// Created by mohamed on 15/07/16.
//

#include "gtest/gtest.h"
#include "../RGBPixel.h"


TEST(RGBPixelTest, DefaultConstructor) {
    RGBPixel rgbPixel;
    ASSERT_EQ(0, rgbPixel.getR());
    ASSERT_EQ(0, rgbPixel.getG());
    ASSERT_EQ(0, rgbPixel.getB());
}

TEST(RGBPixelTest, AssignmentOP) {
    RGBPixel rgbPixel(10, 10, 10);
    RGBPixel rgbPixel1=rgbPixel;
    ASSERT_EQ(rgbPixel.getR(), rgbPixel1.getR());
    ASSERT_EQ(rgbPixel.getG(), rgbPixel1.getG());
    ASSERT_EQ(rgbPixel.getB(), rgbPixel1.getB());
}

TEST(RGBPixelTest, SumAssignOperator) {
    RGBPixel rgbPixel(10, 10, 10);
    RGBPixel rgbPixel1(20, 20, 20);
    rgbPixel+=rgbPixel1;
    ASSERT_EQ(rgbPixel.getR(), 30);
    ASSERT_EQ(rgbPixel.getG(), 30);
    ASSERT_EQ(rgbPixel.getB(), 30);
}

TEST(RGBPixelTest, DivisionAssignOperator) {
    RGBPixel rgbPixel(10, 10, 10);
    rgbPixel/=2;
    ASSERT_EQ(rgbPixel.getR(), 5);
    ASSERT_EQ(rgbPixel.getG(), 5);
    ASSERT_EQ(rgbPixel.getB(), 5);
}

TEST(RGBPixelTest, intAssignOperator) {
    RGBPixel rgbPixel;
    rgbPixel=255;
    ASSERT_EQ(rgbPixel.getR(), 255);
    ASSERT_EQ(rgbPixel.getG(), 255);
    ASSERT_EQ(rgbPixel.getB(), 255);
}