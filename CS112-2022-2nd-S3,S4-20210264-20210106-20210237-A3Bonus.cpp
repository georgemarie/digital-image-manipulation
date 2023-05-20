// FCI – Programming 1 – 2022 - Assignment 3
// Program Name: CS112-203-2nd-S3,S4-20210264-20210106-20210237-A3-Part1.cpp
// Last Modification Date: 23/04/2022
// Author1 and ID and Group: Omar Khaled Mohamed Hamed, ID: 20210264, Group: S3
// Author2 and ID and Group: george marie demyan, ID: 20210106, Group: S3
// Author3 and ID and Group: abdullah mohamed mokhtar, ID: 20210237, Group: S4


#include <iostream>
#include <cstring>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE][RGB];
unsigned char image2[SIZE][SIZE][RGB];
unsigned char merged_image[SIZE][SIZE][RGB];


void loadImage();
void saveImage();
void saveImage2();
void filter1();
void filter2();
void filter3();
void filter4();
void filter5();
void filter6();
void filter7();
void filter8();
void filter9();
void filter_a();
void filter_b();
void filter_c();
void reverse1(int choice);
void reverse2(int choice);
void reverse3(int choice);
void reverse4(int choice);
void loadImage1();
void loadImage2();
void save_merged_image();


int main()
{
    char filter;
    cout << "Ahlan ya user ya habibi" << endl;
    loadImage();
    cout << "Please select a filter to apply or 0 to exit: " << endl;
    cout << "1- Black & White Filter." << endl;
    cout << "2- invert filter." << endl;
    cout << "3- merge 2 photos." << endl;
    cout << "4- flip an image." << endl;
    cout << "5- Rotation filter." << endl;
    cout << "6- Darken and lighten image." << endl;
    cout << "7- Detect image edges." << endl;
    cout << "8- Enlarge image." << endl;
    cout << "9- shrink image." << endl;
    cout << "a- Mirror 1/2 Image." << endl;
    cout << "b- Shuffle image." <<endl;
    cout << "c- Blur Image." << endl;
    cout << "Type 0 to exit." << endl;
    cin >> filter;

    if (filter == '0')
    {
        return 0;
    }
    else if (filter == '1')
    {
        filter1();
    }
    else if (filter == '2')
    {
        filter2();
    }
    else if (filter == '3')
    {
        loadImage1();
        loadImage2();
        filter3();
        save_merged_image();
        return 0;
    }
    else if (filter == '4')
    {
        filter4();
    }
    else if (filter == '5')
    {
        filter5();
    }
    else if (filter == '6')
    {
        filter6();
    }
    else if (filter == '7')
    {
        filter7();
    }
    else if (filter == '8')
    {
        filter8();
        return 0;
    }
    else if (filter == '9')
    {
        filter9();
        return 0;
    }
    else if (filter == 'a')
    {
        filter_a();
    }
    else if (filter == 'b')
    {
        filter_b();
        return 0;
    }
    else if (filter == 'c')
    {
        filter_c();
    }
    else if (filter == '0')
    {
        return 0;
    }
    else
    {
        return 0;
    }
    saveImage();
    return 0;
}


void loadImage() {
    char imageFileName[100];

    cout << "Please enter file name of the image to process: ";
    cin >> imageFileName;

    // add file extension
    strcat(imageFileName, ".bmp");
    readRGBBMP(imageFileName, image);
}


void saveImage () {
    char imageFileName[100];

    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // add file extension
    strcat(imageFileName, ".bmp");
    writeRGBBMP(imageFileName, image);
}


void saveImage2 () {
    char imageFileName[100];

    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // add file extension
    strcat(imageFileName, ".bmp");
    writeRGBBMP(imageFileName, image2);
}

void filter1()
{
    long avg = 0;
    // accessing every pixel in the image and the last for loop accesses the rgb colors to calculate the average.
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; k++)
            {
                avg += image[i][j][k];
            }
        }
    }
    avg /= (SIZE * SIZE * RGB);

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (image[i][j][0] + image[i][j][1] + image[i][j][2] > 3*128)
            {
                image[i][j][0] = 255;
                image[i][j][1] = 255;
                image[i][j][2] = 255;
            }
            else
            {
                image[i][j][0] = 0;
                image[i][j][1] = 0;
                image[i][j][2] = 0;
            }
        }
    }
}


void filter2(){
    //loop to take each index in 3D array
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k <3 ; ++k) {
                image[i][j][k] = 255 - image[i][j][k];
                //to get the complement of the number of the pixel that indicate its colour.
            }
        }
    }
}


void loadImage1()
{
    char image1filename[100];
    cout << "Enter the source image file name: ";
    cin >> image1filename;
    strcat(image1filename, ".bmp");
    readRGBBMP(image1filename, image);
}


void loadImage2()
{
    char image2filename[100];
    cout << "Enter the source image file name: ";
    cin >> image2filename;
    strcat(image2filename, ".bmp");
    readRGBBMP(image2filename, image2);
}


void save_merged_image()
{
    char imagefilename[100];
    cout << "Enter the file you want to save in: ";
    cin >> imagefilename;
    strcat(imagefilename, ".bmp");
    writeRGBBMP(imagefilename, merged_image);
}


void filter3()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; k++)
            {
                merged_image[i][j][k] = int((image[i][j][k] + image2[i][j][k]) / 2);
            }
        }
    }
}


void filter4()
{
    char flip_dir;
    cout << "Do you want to filp the image 1) vertically or 2) horizontally: ";
    cin >> flip_dir;
    // vertical flip
    if (flip_dir == '1')
    {
        for (int i = 0; i < SIZE / 2; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                swap(image[i][j], image[SIZE - i][j]);
            }
        }
    }
    // horizontal flip
    else if (flip_dir == '2')
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE / 2; j++)
            {
                swap(image[i][j], image[i][SIZE - j]);
            }
        }
    }
}


void filter5(){
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


void filter6()
{
    int operating;
    cout << "which operating do you want ?\n 1-darken .\n2- lighten.\n";

    cin >> operating;
    switch (operating)
    {

    case 1:
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k < RGB; k++)
                {
                    image[i][j][k] = image[i][j][k] / 2;
                }
            }
        }
    case 2:
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k < RGB; k++)
                {
                    image[i][j][k] = (image[i][j][k] + 256) / 2;
                }
            }
        }
    }
}


void filter7()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            // calculating the the difference between pixels values to determine if a pixel is an edge
            if (abs(image[i][j][0] - image[i][j + 1][0]) >= 30)
            {
                image[i][j][0] = 0;
                image[i][j][1] = 0;
                image[i][j][2] = 0;
            }
            else
            {
                image[i][j][0] = 255;
                image[i][j][1] = 255;
                image[i][j][2] = 255;
            }
        }
    }
}


void filter8() {
    int direction_x[4] = {0, 1, 0, 1};
    int direction_y[4] = {0, 0, 1, 1};
    int row2 = 0, colum2 = 0;
    int choice;
    cout<< "which quarter you want to enlarge ?\n1-first quarter.\n2-second quarter.\n3-third quarter.\n4-fourth quarter";
    cin >> choice;
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
            saveImage2();
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
                            image2[row2 + direction_x[direction]][colum2 +
                                                                  direction_y[direction]][k] = image[row1][colum1][k];
                        }
                    }
                }
            }
            saveImage2();
            break;
        }
        case 3 : {
            for (int row1 = SIZE / 2; row1 < SIZE; row1++, row2 += 2) {
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
            saveImage2();
            break;
        }
        case 4: {
            for (int row1 = SIZE / 2; row1 < SIZE; row1++, row2 += 2) {
                for (int colum1 = SIZE / 2; colum1 < SIZE; colum1++, colum2 += 2) {
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
            saveImage2();
            break;
        }
    }
}


void filter9()
{
    int operate;
    cout << "if you want to shrink the image to (1/2) enter 1\nif you want to shrink the image to (1/3) enter 2\nif you want to shrink the image to (1/4) enter 3\nif you want to exit enter 0\nenter: ";
    cin >> operate;

    for (int i=0 ; i < SIZE ; ++i){
        for (int j = 0; j <SIZE ; ++j) {
            for (int k = 0; k <3 ; ++k) {
                image2[i][j][k] = 255-image2[i][j][k];
            }
        }
    }

    if (operate == 1) {
        for (int i = 0; i < SIZE; i += 2) {
            for (int j = 0; j < SIZE; j += 2) {
                for (int k = 0; k < 3; ++k) {
                    image2[i / 2][j / 2][k] = image[i][j][k];
                }
            }
        }
    }
    else if (operate == 2) {
        for (int i = 0; i < SIZE; i += 3) {
            for (int j = 0; j < SIZE; j += 3) {
                for (int k = 0; k < 3; ++k) {
                    image2[i / 3][j / 3][k] = image[i][j][k];
                }
            }
        }
    } 
    else if (operate == 3) {
        for (int i = 0; i < SIZE; i += 4) {
            for (int j = 0; j < SIZE; j += 4) {
                for (int k = 0; k < 3; ++k) {
                    image2[i / 4][j / 4][k] = image[i][j][k];
                }
            }
        }
    } 
    else if (operate == 0) {
        exit(0);
    }
    saveImage2();
}


void filter_a() {
    char answer;
    cout << "Mirror (l)eft, (r)ight, (u)pper, (d)own side? ";
    cin >> answer;

    if (answer == 'r') {
        // right mirror
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j][0] = image[i][SIZE - j][0];
                image[i][j][1] = image[i][SIZE - j][1];
                image[i][j][2] = image[i][SIZE - j][2];
            }
        }
    } else if (answer == 'd') {
        // down mirror
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j][0] = image[SIZE - i][j][0];
                image[i][j][1] = image[SIZE - i][j][1];
                image[i][j][2] = image[SIZE - i][j][2];
            }
        }
    } else if (answer == 'u') {
        // upper mirror
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[SIZE - i][j][0] = image[i][j][0];
                image[SIZE - i][j][1] = image[i][j][1];
                image[SIZE - i][j][2] = image[i][j][2];
            }
        }
    } else if (answer == 'l') {
        // left mirror
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][SIZE - j][0] = image[i][j][0];
                image[i][SIZE - j][1] = image[i][j][1];
                image[i][SIZE - j][2] = image[i][j][2];
            }
        }
    }
}


void filter_b(){
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
    saveImage2();
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


void filter_c()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; k++)
            {
                // adding adjacent pixels in one pixel
                image[i][j][k] = (image[i][j][k] + image[i + 1][j][k] + image[i][j + 1][k] + image[i + 1][j + 1][k] + image[i - 1][j][k] + image[i][j - 1][k] + image[i - 1][j - 1][k] + image[i + 2][j][k] + image[i][j + 2][k] + image[i + 2][j + 2][k] + image[i - 2][j][k] + image[i][j - 2][k] + image[i - 2][j - 2][k] + image[i + 3][j][k] + image[i][j + 3][k] + image[i + 3][j + 3][k] + image[i - 3][j][k] + image[i][j - 3][k] + image[i - 3][j - 3][k]) / 19;
            }
        }
    }
}