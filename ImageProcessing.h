//
// Created by mohamed on 11/07/16.
//

#ifndef IMAGEPROCESSING_IMAGEPROCESSING_H
#define IMAGEPROCESSING_IMAGEPROCESSING_H

#include <iostream>
#include "Image.h"

using namespace std;


template <typename T>
class ImageProcessing {
public:
    ImageProcessing(Image *im= nullptr) : image(im){}
    Image* blur() {
        T sum;
        for(int i=1; i<image->width-1; i++) {

            for (int j = 1; j < image->height - 1; j++) {
                sum=0;
                for (int ik = i - 1, n=0;ik<i+2; ik++)
                    for (int jk = j - 1;jk<j+2 ; jk++) {
                        kernel[n] = image->image[ik * image->width + jk];
                        sum += kernel[n];
                        n++;
                    }
                sum /= 9;
                image->image[i * image->width + j] = sum;
            }
        }
        return image;
    }


    const Image &getImage() const {
        return *image;
    }

private:
    Image *image;
    T kernel[3*3];



};




#endif //IMAGEPROCESSING_IMAGEPROCESSING_H
