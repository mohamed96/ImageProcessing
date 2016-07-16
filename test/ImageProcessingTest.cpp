//
// Created by mohamed on 15/07/16.
//

#include "gtest/gtest.h"
#include "../ImageProcessing.h"
#include "../Image.h"

TEST(ImageProcessingTest, DefaultConstructor) {
    ImageProcessing<int> processing;
    ASSERT_EQ(0, processing.getWidth());
    ASSERT_EQ(0, processing.getHeight());
}


TEST(ImageProcessingTest, BlurTest) {
    Image image(4, 4);
    for(int i=0;i<image.width;i++)
        for(int j=0;j<image.height;j++)
            image.image[i*image.width+j]=(i*image.width+j);
    ImageProcessing<RGBPixel> processing;
    processing.blur(image.width, image.height, image.image);
    ASSERT_EQ(image.image[1*image.width+1].getR(), 5);
    ASSERT_EQ(image.image[1*image.width+1].getG(), 5);
    ASSERT_EQ(image.image[1*image.width+1].getB(), 5);
    ASSERT_EQ(image.image[1*image.width+2].getR(), 6);
    ASSERT_EQ(image.image[1*image.width+2].getG(), 6);
    ASSERT_EQ(image.image[1*image.width+2].getB(), 6);
}
