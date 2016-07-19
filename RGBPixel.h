//
// Created by mohamed on 12/07/16.
//

#ifndef IMAGEPROCESSING_RGBPIXEL_H
#define IMAGEPROCESSING_RGBPIXEL_H


class RGBPixel {
public:
    RGBPixel(float r=0, float g=0, float b=0) : R(r), G(g), B(b) {}

    float getR() const ;
    void setR(float r);
    float getG() const ;
    void setG(float g);
    float getB() const ;
    void setB(float b);
    RGBPixel& operator += (const RGBPixel & right);
    const RGBPixel& operator = (const RGBPixel & right);
    const RGBPixel& operator = (int n);
    RGBPixel& operator /= (int n);
    RGBPixel& operator *= (const RGBPixel& right);

    float R, G, B;

};


#endif //IMAGEPROCESSING_RGBPIXEL_H
