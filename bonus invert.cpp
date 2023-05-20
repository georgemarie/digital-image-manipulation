#include<iostream>
#include <fstream>
#include <cstring>
#include<cmath>
#include "bmplib.cpp"
using namespace std;
unsigned char image[SIZE][SIZE][RGB];
void loadImage(){
    char imagefilename[100];
    cout << "Enter the source image file name: " ;
    cin >>imagefilename;
    strcat(imagefilename,".bmp");
    readRGBBMP(imagefilename , image);
}
void save_image(){
    char imagefilename[100];
    cout << "Enter the file you want to save in: ";
    cin >>imagefilename;
    strcat(imagefilename,".bmp");
    writeRGBBMP(imagefilename , image);
}
//function to invert the photo//
void filter_for_image() {
    //loop to take each index in 2D array
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k <3 ; ++k) {
                image[i][j][k] = 255 - image[i][j][k];
                //to get the complement of the number of the pixel that indicate its colour.
            }
        }
    }
}
int main() {
    loadImage();
    filter_for_image();
    save_image();
}
