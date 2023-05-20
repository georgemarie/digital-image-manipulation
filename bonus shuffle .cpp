#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"
using namespace std;
unsigned char image[SIZE][SIZE][RGB];
unsigned char image2[SIZE][SIZE][RGB];
void loadImage();
void reverse1();
void reverse2();
void reverse3();
void reverse4();
void saveImage2();
void dosomethingforimage();
int main()
{
    loadImage();
    dosomethingforimage();
    saveImage2();
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
void saveImage2() {
    char imageFileName[100];
    cout << "Enter the target image file name: ";
    cin >> imageFileName;
    strcat (imageFileName, ".bmp");
    writeRGBBMP(imageFileName, image2);
}
void reverse1(int choice){
    int row = 0 , col = 0;
    switch(choice) {
        case 1 :
            for (int i = 0; i < SIZE / 2; ++i , ++row ) {
                for (int j = 0; j < SIZE / 2; ++j, ++col) {
                    for (int k = 0; k < 3; ++k) {
                        if (col == SIZE / 2) {
                            col = 0;
                        }
                        image2[i][j][k] = image[row][col][k];
                    }
                }
            }
            break;
        case 2 :
            for (int i = 0; i < SIZE / 2; ++i , ++row) {
                for (int j = SIZE / 2; j < SIZE; ++j, ++col) {
                    for (int k = 0; k < 3; ++k) {
                        if (col == SIZE / 2) {
                            col = 0;
                        }
                        image2[i][j][k] = image[row][col][k];
                    }
                }
            }
            break;
        case 3 :
            for (int i = SIZE / 2; i < SIZE; ++i , ++row) {
                for (int j = 0; j < SIZE / 2; ++j , ++col) {
                    for (int k = 0; k < 3; ++k) {
                        if (col == SIZE / 2) {
                            col = 0;
                        }
                        image2[i][j][k] = image[row][col][k];
                    }
                }
            }
            break;
        case 4 :
            for (int i = SIZE / 2; i < SIZE; ++i , ++row) {
                for (int j = SIZE / 2; j < SIZE; ++j , ++col) {
                    for (int k = 0; k < 3; ++k) {
                        if (col == SIZE / 2) {
                            col = 0;
                        }
                        image2[i][j][k] = image[row][col][k];
                    }
                }
            }
            break;
    }
}
void reverse2(int choice){
    int row = 0 , col = SIZE/2 ;
    switch(choice) {
        case 1 :
            for (int i = 0; i < SIZE / 2; ++i , ++row ) {
                for (int j = 0; j < SIZE / 2; ++j, ++col) {
                    for (int k = 0; k < 3; ++k) {
                        if (col == SIZE) {
                            col = SIZE / 2;
                        }
                        image2[i][j][k] = image[row][col][k];
                    }
                }
            }
            break;
        case 2 :
            for (int i = 0; i < SIZE / 2; ++i , ++row) {
                for (int j = SIZE / 2; j < SIZE; ++j, ++col) {
                    for (int k = 0; k < 3; ++k) {
                        if (col == SIZE) {
                            col = SIZE / 2;
                        }
                        image2[i][j][k] = image[row][col][k];
                    }
                }
            }
            break;
        case 3 :
            for (int i = SIZE / 2; i < SIZE; ++i , ++row) {
                for (int j = 0; j < SIZE / 2; ++j, ++col) {
                    for (int k = 0; k < 3; ++k) {
                        if (col == SIZE) {
                            col = SIZE / 2;
                        }
                        image2[i][j][k] = image[row][col][k];
                    }
                }
            }
            break;
        case 4 :
            for (int i = SIZE / 2; i < SIZE; ++i , ++row) {
                for (int j = SIZE / 2; j < SIZE; ++j , ++col) {
                    for (int k = 0; k < 3; ++k) {
                        if (col == SIZE) {
                            col = SIZE / 2;
                        }
                        image2[i][j][k] = image[row][col][k];
                    }
                }
            }
            break;
    }
}
void reverse3(int choice){
    int row = SIZE/2 , col = 0 ;
    switch(choice) {
        case 1 :
            for (int i = 0; i < SIZE / 2; ++i , ++row ) {
                for (int j = 0; j < SIZE / 2; ++j, ++col) {
                    for (int k = 0; k < 3; ++k) {
                        if (col == SIZE / 2) {
                            col = 0;
                        }
                        image2[i][j][k] = image[row][col][k];
                    }
                }
            }
            break;
        case 2 :
            for (int i = 0; i < SIZE / 2; ++i , ++row) {
                for (int j = SIZE / 2; j < SIZE; ++j, ++col) {
                    for (int k = 0; k < 3; ++k) {
                        if (col == SIZE / 2) {
                            col = 0;
                        }
                        image2[i][j][k] = image[row][col][k];
                    }
                }
            }
            break;
        case 3 :
            for (int i = SIZE / 2; i < SIZE; ++i , ++row) {
                for (int j = 0; j < SIZE / 2; ++j , ++col) {
                    for (int k = 0; k < 3; ++k) {
                        if (col == SIZE / 2) {
                            col = 0;
                        }
                        image2[i][j][k] = image[row][col][k];
                    }
                }
            }
            break;
        case 4 :
            for (int i = SIZE / 2; i < SIZE; ++i , ++row) {
                for (int j = SIZE / 2; j < SIZE; ++j , ++col) {
                    for (int k = 0; k < 3; ++k) {
                        if (col == SIZE / 2) {
                            col = 0;
                        }
                        image2[i][j][k] = image[row][col][k];
                    }
                }
            }
            break;
    }
}
void reverse4(int choice){
    int row = SIZE/2 , col = SIZE/2;
    switch(choice) {
        case 1 :
            for (int i = 0; i < SIZE / 2; ++i , ++row ) {
                for (int j = 0; j < SIZE / 2; ++j , ++col) {
                    for (int k = 0; k < 3; ++k) {
                        if (col == SIZE) {
                            col = SIZE / 2;
                        }
                        image2[i][j][k] = image[row][col][k];
                    }
                }
            }
            break;
        case 2 :
            for (int i = 0; i < SIZE / 2; ++i , ++row) {
                for (int j = SIZE / 2; j < SIZE; ++j, ++col) {
                    for (int k = 0; k < 3; ++k) {
                        if (col == SIZE) {
                            col = SIZE / 2;
                        }
                        image2[i][j][k] = image[row][col][k];
                    }
                }
            }
            break;
        case 3 :
            for (int i = SIZE / 2; i < SIZE; ++i , ++row) {
                for (int j = 0; j < SIZE / 2; ++j , ++col) {
                    for (int k = 0; k < 3; ++k) {
                        if (col == SIZE) {
                            col = SIZE / 2;
                        }
                        image2[i][j][k] = image[row][col][k];
                    }
                }
            }
            break;
        case 4 :
            for (int i = SIZE / 2; i < SIZE; ++i , ++row) {
                for (int j = SIZE / 2; j < SIZE; ++j , ++col) {
                    for (int k = 0; k < 3; ++k) {
                        if (col == SIZE) {
                            col = SIZE / 2;
                        }
                        image2[i][j][k] = image[row][col][k];
                    }
                }
            }
            break;
    }
}
void dosomethingforimage() {
    for (int i = 0; i < SIZE / 2; ++i ) {
        for (int j = 0; j < SIZE / 2; ++j) {
            for (int k = 0; k < 3; ++k) {
                image2[i][j][k] = image[i][j][k];
            }
        }
    }
    for (int i = 0; i < SIZE / 2; ++i) {
        for (int j = SIZE / 2; j < SIZE; ++j) {
            for (int k = 0; k < 3; ++k) {
                image2[i][j][k] = image[i][j][k];
            }
        }
    }
    for (int i = SIZE / 2; i < SIZE; ++i) {
        for (int j = 0; j < SIZE / 2; ++j) {
            for (int k = 0; k < 3; ++k) {
                image2[i][j][k] = image[i][j][k];
            }
        }
    }
    for (int i = SIZE / 2; i < SIZE; ++i) {
        for (int j = SIZE / 2; j < SIZE; ++j) {
            for (int k = 0; k < 3; ++k) {
                image2[i][j][k] = image[i][j][k];
            }
        }
    }
    int q[4] ;
    for (int i = 0; i <4 ; ++i) {
        cout << " please enter index " << i <<endl;
        cin >> q[i];
    }
    for (int i = 0; i <4 ; ++i) {
        if (q[i]==1){
            reverse1(i+1);
        }
        if (q[i]==2){
            reverse2(i+1);
        }
        if (q[i]==3){
            reverse3(i+1);
        }
        if (q[i]==4){
            reverse4(i+1);
        }
    }

}