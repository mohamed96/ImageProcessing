//
// Created by mohamed on 15/07/16.
//

#include "gtest/gtest.h"
#include "../ImageProcessing.h"


TEST(ImageProcessingTest, applyFiltertest) {
    Image *image=new Image(4, 4);
    RGBPixel *kernel=new RGBPixel[3*3];
    for(int i = 0; i<3; i++)
        for( int j=0; j<3; j++)
            kernel[i*3+j]=1;
    for(int i=0;i<image->width;i++)
        for(int j=0;j<image->height;j++)
            image->image[i*image->width+j]=(i*image->width+j);
    ImageProcessing<Image, RGBPixel> processing(image, kernel, 3*3);
    processing.applyFilter();
    ASSERT_EQ(image->image[1*image->width+1].getR(), 5);
    ASSERT_EQ(image->image[1*image->width+1].getG(), 5);
    ASSERT_EQ(image->image[1*image->width+1].getB(), 5);
    ASSERT_EQ(image->image[1*image->width+2].getR(), 6);
    ASSERT_EQ(image->image[1*image->width+2].getG(), 6);
    ASSERT_EQ(image->image[1*image->width+2].getB(), 6);
}
