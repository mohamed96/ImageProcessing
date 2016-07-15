//
// Created by mohamed on 12/07/16.
//

#ifndef IMAGEPROCESSING_BITMAPIMAGE_H
#define IMAGEPROCESSING_BITMAPIMAGE_H

#include <vector>
#include "RGBPixel.h"

using namespace std;

class Image {
public:
    Image(int w=3, int h=3) : width(w), height(h) {image=new RGBPixel[w*h];}


    unsigned int width, height;
    RGBPixel* image;


};


#endif //IMAGEPROCESSING_BITMAPIMAGE_H
