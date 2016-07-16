#include <iostream>
#include <fstream>
#include <cstring>
#include "Image.h"
#include "ImageProcessing.h"

Image* readPPM(const char *filename);
void savePPM(const Image &img, const char *filename);
using namespace std;

int main() {

    try {
        Image *img = readPPM("/home/mohamed/Scaricati/ppmimages/sign_1.ppm");
        for (int i = 0; i < img->width; i++) {
            cout << endl;
            for (int j = 0; j < img->height; j++) {
                cout << img->image[i * img->width + j].getR() * 255 << " ";
                cout << img->image[i * img->width + j].getG() * 255 << " ";
                cout << img->image[i * img->width + j].getB() * 255 << " ";
            }
        }
        ImageProcessing<RGBPixel> processing(img);
        img=processing.blur();
        savePPM(*img, "/home/mohamed/Scaricati/ppmimages/sign.ppm");

    }

    catch (runtime_error &runtimeError) {
        cout << runtimeError.what();
    }
    cout << "\n\n\n\n\n\n\n\n\n";
    Image *img1 = readPPM("/home/mohamed/Scaricati/ppmimages/sign.ppm");
    for (int i = 0; i < img1->width; i++) {
        cout << endl;
        for (int j = 0; j < img1->height; j++) {
            cout << img1->image[i * img1->width + j].getR() * 255 << " ";
            cout << img1->image[i * img1->width + j].getG() * 255 << " ";
            cout << img1->image[i * img1->width + j].getB() * 255 << " ";
        }


    }
}



Image* readPPM(const char *filename){
    ifstream ifs;
    ifs.open(filename, std::ios::binary );

    if(ifs.is_open()==false)
        throw runtime_error("Failed to open file");
    string header;
    int w, h, b;
    ifs >> header;
    if (strcmp(header.c_str(), "P6")!=0)
        throw runtime_error("can't read input file");
    ifs >> w >> h >> b;
    Image *img=new Image(w,h);
    ifs.ignore(256, '\n');
    unsigned char pix[3];
    for(int i=0; i<w; i++)
        for(int j=0; j<h;j++){
            ifs.read(reinterpret_cast<char *>(pix), 3);
            img->image[i*w+j].R=pix[0] / 255.f;
            img->image[i*w+j].G=pix[1] / 255.f;
            img->image[i*w+j].B=pix[2] / 255.f;
            //img->image[i*w+j].setR(pix[0] / 255.f);
            //img->image[i*w+j].setG(pix[1] / 255.f);
            //img->image[i*w+j].setB(pix[2] / 255.f);
        }
    ifs.close();
    return img;
}

void savePPM(const Image &img, const char *filename) {
    if (img.width == 0 || img.height == 0) {
        cout<<"can't open";
    }
    std::ofstream ofs;
    ofs.open(filename, std::ios::binary);// need to spec. binary mode for Windows users
    if (ofs.fail()) throw("Can't open output file");
    ofs << "P6\n" << img.width << " " << img.height<< "\n255\n";
    unsigned char pix[3]; // loop over each pixel in the image, clamp and convert to byte format
    for (int i = 0; i < img.width; i++) {
        for (int j = 0; j < img.height; j++) {
            //img.image[i*img.width+j].setR(0);
            //img.image[i*img.width+j].setG(0);
            //img.image[i*img.width+j].setB(0);
            pix[0] = static_cast<unsigned char>((img.image[i * img.width + j].R) * 255);
            pix[1] = static_cast<unsigned char>((img.image[i * img.width + j].G) * 255);
            pix[2] = static_cast<unsigned char>((img.image[i * img.width + j].B) * 255);
            ofs.write( reinterpret_cast<char *>(pix), 3);
        }
    }

    ofs.close();
}