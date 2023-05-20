#include<iostream>
#include <fstream>
#include <cstring>
#include<cmath>
#include "bmplib.cpp"
#include<array>
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
void filter_for_image() {
    //switch case to know which rotation the user want
    int rotation;
    cout << "which rotation do you want ?\n 1-Rotate 90 degree.\n2-Rotate 180 degree.\n3-Rotate 270 degree.\n";
    cin >> rotation;
    switch (rotation) {
        case 1:
            // if he choose 90 degree : //
            for (int i = 0; i <SIZE ; ++i) {
                for (int j = i; j < SIZE; ++j) {
                    for (int k = 0; k < 3; ++k) {
                        swap(image[i][j][k], image[j][i][k]);
                        //we get the transpose of the 2D array//
                    }
                }
            }
            for (int i = 0; i < SIZE; ++i) {
                for (int j = 0; j < SIZE / 2; j++) {
                    for (int k = 0; k < 3; ++k) {
                        int number1 = image[i][j][k];
                        image[i][j][k] = image[i][255 - j][k];
                        image[i][255 - j][k] = number1;
                        //we get the horizontal flip of it after transpose//
                    }
                }
            }
            break;
        case 2:
            // if he choose 180 degree : //
            for (int i = 0; i < SIZE; ++i) {
                for (int j = 0; j < SIZE / 2; j++) {
                    for (int k = 0; k < 3; ++k) {
                        int number1 = image[i][j][k];
                        image[i][j][k] = image[i][255 - j][k];
                        image[i][255 - j][k] = number1;
                        // we get horizontal flip of photo//
                    }
                }
            }
            for (int i = 0; i < SIZE/2; i++) {
                for (int j = 0; j < SIZE; j++) {
                    for (int k = 0; k < 3; ++k) {
                        int number2 = image[i][j][k];
                        image[i][j][k] = image[255 - i][j][k];
                        image[255 - i][j][k] = number2;
                        //after horizontal flip we get the vertical flip//
                    }
                }
            }
            break;
        case 3:
            // if he choose 270 degre : //
            for (int i = 0; i <SIZE ; ++i) {
                for (int j = i; j < SIZE; ++j) {
                    for (int k = 0; k < 3; ++k) {
                        swap(image[i][j][k], image[j][i][k]);
                        // we get the transpose of photo //
                    }
                }
            }
            for (int i = 0; i < SIZE; ++i) {
                for (int j = 0; j < SIZE / 2; j++) {
                    for (int k = 0; k < 3; ++k) {
                        int number = image[i][j][k];
                        image[i][j][k] = image[i][255 - j][k];
                        image[i][255 - j][k] = number;
                        // we get the horizontal flip of photo//
                    }
                }
            }
            for (int i = 0; i < SIZE; ++i) {
                for (int j = 0; j < SIZE / 2; j++) {
                    for (int k = 0; k < 3; ++k) {
                        int number = image[i][j][k];
                        image[i][j][k] = image[i][255 - j][k];
                        image[i][255 - j][k] = number;
                        // another horizontal flip to the photo//
                    }
                }
            }
            for (int i = 0; i < SIZE/2; ++i) {
                for (int j = 0; j < SIZE; j++) {
                    for (int k = 0; k < 3; ++k) {
                        int number = image[i][j][k];
                        image[i][j][k] = image[255 - i][j][k];
                        image[255 - i][j][k] = number;
                        // after that vertical flip for the photo //
                    }
                }
            }
    }
}
int main() {
    loadImage();
    filter_for_image();
    save_image();
}
