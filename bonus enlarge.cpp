#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE][RGB];
unsigned char image2[SIZE][SIZE][RGB];
void loadImage ();
void saveImage ();
void Enlarge_image();
int main()
{
    loadImage();
    Enlarge_image();
    saveImage();
    return 0;
}

//_________________________________________
void loadImage () {
    char imageFileName[100];
    cout << "Enter the source image file name: ";
    cin >> imageFileName;
    strcat (imageFileName, ".bmp");
    readRGBBMP(imageFileName, image);
}

//_________________________________________
void saveImage () {
    char imageFileName[100];
    cout << "Enter the target image file name: ";
    cin >> imageFileName;
    strcat (imageFileName, ".bmp");
    writeRGBBMP(imageFileName, image2);
}
void Enlarge_image(){
    int direction_x[4] = {0,1,0,1};
    int direction_y[4] = {0,0,1,1};
    int row2 = 0 , colum2 = 0;
    int choice;
    cout<<"which quarter you want to enlarge ?\n1-first quarter.\n2-second quarter.\n3-third quarter.\n4-fourth quarter";
    cin>>choice;
    switch (choice) {
        case 1 : {
            for (int row1 = 0; row1 < SIZE / 2; row1++, row2 += 2) {
                for (int colum1 = 0; colum1 < SIZE / 2; colum1++, colum2 += 2) {
                    for (int k = 0; k < 3; ++k) {
                        if (colum2 >= SIZE) {
                            colum2 = 0;
                        }
                        for (int direction = 0; direction < 4; direction++) {
                            image2[row2 + direction_x[direction]][colum2 +
                                                                  direction_y[direction]][k] = image[row1][colum1][k];
                        }
                    }
                }
            }
            break;
        }
        case 2 : {
            for (int row1 = 0; row1 < SIZE / 2; row1++, row2 += 2) {
                for (int colum1 = SIZE / 2; colum1 < SIZE; colum1++, colum2 += 2) {
                    for (int k = 0; k < 3; ++k) {
                        if (colum2 >= SIZE) {
                            colum2 = 0;
                        }
                        for (int direction = 0; direction < 4; direction++) {
                            image2[row2 + direction_x[direction]][colum2 +direction_y[direction]][k] = image[row1][colum1][k];
                        }
                    }
                }
            }
            break;
        }
        case 3 :
        {
            for (int row1 = SIZE/2; row1 < SIZE; row1++,row2+=2) {
                for (int colum1 = 0; colum1 < SIZE / 2; colum1++, colum2 += 2) {
                    for (int k = 0; k < 3; ++k) {
                        if (colum2 >= SIZE) {
                            colum2 = 0;
                        }
                        for (int direction = 0; direction < 4; direction++) {
                            image2[row2 + direction_x[direction]][colum2 +direction_y[direction]][k] = image[row1][colum1][k];
                        }
                    }
                }
            }
            break;
        }
        case 4:
        {
            for (int row1 = SIZE/2; row1 < SIZE; row1++,row2+=2) {
                for (int colum1 = SIZE/2; colum1< SIZE; colum1++ , colum2+=2) {
                    for (int k = 0; k < 3; ++k) {
                        if (colum2 >= SIZE) {
                            colum2 = 0;
                        }
                        for (int direction = 0; direction < 4; direction++) {
                            image2[row2 + direction_x[direction]][colum2 +direction_y[direction]][k] = image[row1][colum1][k];
                        }
                    }
                }
            }
            break;
        }
    }
}