//
// Created by mohamed on 11/07/16.
//

#ifndef IMAGEPROCESSING_IMAGEPROCESSING_H
#define IMAGEPROCESSING_IMAGEPROCESSING_H

#include <iostream>

using namespace std;


template <typename T>
class ImageProcessing {
public:
    ImageProcessing(int w=0, int h=0) : width(w), height(h){}
    T blur(int w, int h, T* img) {
        T sum;
        for(int i=1; i<w-1; i++) {

            for (int j = 1; j < h - 1; j++) {
                sum=0;
                for (int ik = i - 1, n=0;ik<i+2; ik++)
                    for (int jk = j - 1;jk<j+2 ; jk++) {
                        kernel[n] = img[ik * w + jk];
                        sum += kernel[n];
                        n++;
                    }
                sum /= 9;
                img[i * w + j] = sum;
            }
        }
    }

    int getWidth() const {
        return width;
    }
    int getHeight() const {
        return height;
    }


private:
    int width, height;
    T kernel[3*3];



};




#endif //IMAGEPROCESSING_IMAGEPROCESSING_H
