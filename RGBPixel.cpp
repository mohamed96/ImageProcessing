//
// Created by mohamed on 12/07/16.
//

#include "RGBPixel.h"


float RGBPixel::getR() const {
    return R;
}

void RGBPixel::setR(float r) {
    R=r;
}

float RGBPixel::getG() const {
    return G;
}

void RGBPixel::setG(float g) {
    G=g;
}

float RGBPixel::getB() const {
    return B;
}

void RGBPixel::setB(float b) {
    B=b;
}

const RGBPixel& RGBPixel::operator=(const RGBPixel &right) {
    if (R!=right.R)
        R=right.R;
    if (G!=right.G)
        G=right.G;
    if (B!=right.G)
        B=right.B;
    return *this;
}



RGBPixel &RGBPixel::operator/=(int n) {
    this->R=this->R/n;
    this->G=this->G/n;
    this->B=this->B/n;
    return *this;
}

RGBPixel& RGBPixel::operator+=(const RGBPixel &right) {
    this->R+=right.R;
    this->G+=right.G;
    this->B+=right.B;
    return *this;
}

const RGBPixel &RGBPixel::operator=(int n) {
    this->R=n;
    this->G=n;
    this->B=n;
    return *this;
}

RGBPixel& RGBPixel::operator*=(const RGBPixel &right){
    this->R*=right.R;
    this->G*=right.G;
    this->B*=right.B;
    return *this;
}











/*const RGBPixel &RGBPixel::operator/(RGBPixel &right) {
    if(right.R!=0)
        this->R/right.R;

}*/


























