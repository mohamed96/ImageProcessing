//
// Created by mohamed on 11/07/16.
//

#ifndef IMAGEPROCESSING_IMAGEPROCESSING_H
#define IMAGEPROCESSING_IMAGEPROCESSING_H

#include <iostream>
#include "Image.h"

using namespace std;


template <typename T, typename T1>
class ImageProcessing {
public:

    ImageProcessing(T *im, T1 *k, int n) :  image(im), kernel(k), N(n){ }
    T* applyFilter() {
        T1 pixel;
        T1 sum;
        if (image == nullptr)
            throw runtime_error("NO IMAGE TO PROCESS.");
        for(int i=1; i<image->width-1; i++) {

            for (int j = 1; j < image->height - 1; j++) {
                sum=0;
                for (int ik = i - 1, n=0;ik<i+2; ik++)
                    for (int jk = j - 1;jk<j+2; jk++) {
                        pixel=(kernel[n]);
                        pixel*=(image->image[ik * image->width + jk]);
                        sum+=pixel;
                        n++;
                    }
                sum /= 9;
                image->image[i * image->width + j] = sum;
            }
        }
        return image;
    }


    const T &getImage() const {
        return *image;
    }

private:
    T *image;
    T1 *kernel;
    int N;



};




#endif //IMAGEPROCESSING_IMAGEPROCESSING_H
