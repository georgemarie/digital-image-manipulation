// FCI – Programming 1 – 2022 - Assignment 3
// Program Name: CS112-203-2nd–S3,S4-20210264-20210106-20210237-A3-FULL.cpp
// Last Modification Date: 23/04/2022
// Author1 and ID and Group: Omar Khaled Mohamed Hamed, ID: 20210264, Group: S3
// Author2 and ID and Group: george marie demyan, ID: 20210106, Group: S3
// Author3 and ID and Group: abdullah mohamed mokhtar, ID: 20210237, Group: S4


#include <iostream>
#include <cstring>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image1[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char merged_image[SIZE][SIZE];

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
    cout << "8- Enlarge image."<< endl;
    cout << "9- shrink image." << endl;
    cout << "a- Mirror 1/2 Image." << endl;
    cout << "b- Shuffle image." <<endl;
    cout << "c- blur image." << endl;
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

    // Get gray scale image file name
    cout << "Please enter file name of the image to process: ";
    cin >> imageFileName;

    // add file extension
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}


void saveImage () {
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // add file extension
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}


void saveImage2(){
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // add file extension
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, image2);
}


void filter1()
{
    long avg = 0;
    // calculating average black and white colors in the image
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            avg += image[i][j];
        }
    }
    avg /= (SIZE * SIZE);

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (image[i][j] > avg)
            {
                image[i][j] = 255;
            }
            else
            {
                image[i][j] = 0;
            }
        }
    }
}


// nested loop to invert the photo
void filter2() {
    // loop to take each index in 2D array
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = 255 - image[i][j];
        }
    }
}


void filter3()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            merged_image[i][j] = int((image1[i][j] + image2[i][j]) / 2);
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


void filter5() {
    int rotation;
    cout << "which rotation do you want ?\n 1-Rotate 90 degree.\n2-Rotate 180 degree.\n3-Rotate 270 degree.\n";
    cin >> rotation;
    // switch case to know which rotation the user want.
    switch (rotation) {
        case 1:
            // if he choose 90 degree
            for (int i = 0; i < SIZE; ++i) {
                for (int j = i; j < SIZE; ++j) {
                    swap(image[i][j], image[j][i]);
                }
            }
            for (int i = 0; i < SIZE; ++i) {
                for (int j = 0; j < SIZE / 2; j++) {
                    int number1 = image[i][j];
                    image[i][j] = image[i][255 - j];
                    image[i][255 - j] = number1;
                }
            }
            break;
        case 2:
            // if he choose 180 degree
            for (int i = 0; i < SIZE; ++i) {
                for (int j = 0; j < SIZE / 2; j++) {
                    int number1 = image[i][j];
                    image[i][j] = image[i][255 - j];
                    image[i][255 - j] = number1;
                }
            }
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 0; j < SIZE; j++) {
                    int number2 = image[i][j];
                    image[i][j] = image[255 - i][j];
                    image[255 - i][j] = number2;
                }
            }
            break;
        case 3:
            // if he choose 270 degre
            for (int i = 0; i < SIZE; ++i) {
                for (int j = i; j < SIZE; ++j) {
                    swap(image[i][j], image[j][i]);
                }
            }
            for (int i = 0; i < SIZE; ++i) {
                for (int j = 0; j < SIZE / 2; j++) {
                    int number = image[i][j];
                    image[i][j] = image[i][255 - j];
                    image[i][255 - j] = number;
                }
            }
            for (int i = 0; i < SIZE; ++i) {
                for (int j = 0; j < SIZE / 2; j++) {
                    int number = image[i][j];
                    image[i][j] = image[i][255 - j];
                    image[i][255 - j] = number;
                }
            }
            for (int i = 0; i < SIZE / 2; ++i) {
                for (int j = 0; j < SIZE; j++) {
                    int number = image[i][j];
                    image[i][j] = image[255 - i][j];
                    image[255 - i][j] = number;
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
                    image[i][j] = image[i][j] / 2;
                }
            }
        case 2:
            for (int i = 0; i < SIZE; i++)
            {
                for (int j = 0; j < SIZE; i++)
                {
                    image[i][j] = (image[i][j] + 256) / 2;
                }
            }
    }
}


void filter7()
{
    // detecting edges
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            // calculating the the difference between pixels values to determine if a pixel is an edge
            if (abs(image[i][j] - image[i][j + 1]) >= 30)
            {
                image[i][j] = 0;
            }
            else
            {
                image[i][j] = 255;
            }
        }
    }
}


void filter8() {
    //directions is done to put each pixel en 4 places by increment the place.
    int direction_x[4] = {0, 1, 0, 1};
    int direction_y[4] = {0, 0, 1, 1};
    int row2 = 0, colum2 = 0;
    //row2 and colum2 is done to use them in the new image.
    int choice;
    cout
            << "which quarter you want to enlarge ?\n1-first quarter.\n2-second quarter.\n3-third quarter.\n4-fourth quarter";
    cin >> choice;
    //switch case to know which quarter the user want to enlarge.
    switch (choice) {
        // we put in image2 :row2+the direction from which the index repeat
        //col2+the direction from which the index repeat and so we repeat the pixel in 4 places
        //the original pixel and right it and under it and right under the pixel and we repeat this in the 4 cases.
        case 1 : {
            for (int row1 = 0; row1 < SIZE / 2; row1++, row2 += 2) {
                for (int colum1 = 0; colum1 < SIZE / 2; colum1++, colum2 += 2) {
                    if (colum2 >= SIZE) {
                        colum2 = 0;
                    //we make this condition to make the colum when reach to 256 return to zero to continue.
                    // we increment row2,col2 by 2 as we take the second pixel right original when we repeat the pixel.
                    }
                    for (int direction = 0; direction < 4; direction++) {
                        image2[row2 + direction_x[direction]][colum2 + direction_y[direction]] = image[row1][colum1];

                    }
                }
            }
            //case 1 is when he want first quarter.
            break;
        }
        case 2 : {
            for (int row1 = 0; row1 < SIZE / 2; row1++, row2 += 2) {
                for (int colum1 = SIZE / 2; colum1 < SIZE; colum1++, colum2 += 2) {
                    if (colum2 >= SIZE) {
                        colum2 = 0;
                    }
                    for (int direction = 0; direction < 4; direction++) {
                        image2[row2 + direction_x[direction]][colum2 + direction_y[direction]] = image[row1][colum1];
                    }
                }
            }
            //case 2 is when he want second quarter.
            break;
        }
        case 3 : {
            for (int row1 = SIZE / 2; row1 < SIZE; row1++, row2 += 2) {
                for (int colum1 = 0; colum1 < SIZE / 2; colum1++, colum2 += 2) {
                    if (colum2 >= SIZE) {
                        colum2 = 0;
                    }
                    for (int direction = 0; direction < 4; direction++) {
                        image2[row2 + direction_x[direction]][colum2 + direction_y[direction]] = image[row1][colum1];
                    }
                }
            }
            //case 3 is when he want third quarter.
            break;
        }
        case 4: {
            for (int row1 = SIZE / 2; row1 < SIZE; row1++, row2 += 2) {
                for (int colum1 = SIZE / 2; colum1 < SIZE; colum1++, colum2 += 2) {
                    if (colum2 >= SIZE) {
                        colum2 = 0;
                    }
                    for (int direction = 0; direction < 4; direction++) {
                        image2[row2 + direction_x[direction]][colum2 + direction_y[direction]] = image[row1][colum1];
                    }
                }
            }
            //case 4 is when he want fourth quarter.
            break;
        }
    }
    saveImage2();
    //and after that we save this in new image with the new size.
}


void filter9() // Function for the filter to be implemented for the image
{
    int operate;
    cout << "if you want to shrink the image to (1/2) enter 1\nif you want to shrink the image to (1/3) enter 2\nif you want to shrink the image to (1/4) enter 3\nif you want to exit enter 0\nenter: ";
    cin >> operate;
    for (int i=0 ; i <SIZE ; ++i){
        for (int j = 0; j < SIZE ; ++j) {
            image2[i][j] = 255 - image2[i][j];
        }
    }
    if (operate == 1) {
        for (int i = 0; i < SIZE; i += 2) {
            for (int j = 0; j < SIZE; j += 2) {
                image2[i / 2][j / 2] = image[i][j];
            }
        }
    } else if (operate == 2) {
        for (int i = 0; i < SIZE; i += 3) {
            for (int j = 0; j < SIZE; j += 3) {
                image2[i / 3][j / 3] = image[i][j];
            }
        }
    } else if (operate == 3) {
        for (int i = 0; i < SIZE; i += 4) {
            for (int j = 0; j < SIZE; j += 4) {
                image2[i / 4][j / 4] = image[i][j];
            }
        }
    } else if (operate == 0) {
        exit(0);
    }
    saveImage2();
}


void filter_a()
{
    char answer;
    cout << "Mirror (l)eft, (r)ight, (u)pper, (d)own side? ";
    cin >> answer;

    if (answer == 'r')
    {
        // right mirror
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                image[i][j] = image[i][SIZE - j];
            }
        }
    }
    else if (answer == 'd')
    {
        // down mirror
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                image[i][j] = image[SIZE - i][j];
            }
        }
    }
    else if (answer == 'u')
    {
        // upper mirror
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                image[SIZE - i][j] = image[i][j];
            }
        }
    }
    else if (answer == 'l')
    {
        // left mirror
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                image[i][SIZE - j] = image[i][j];
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
    readGSBMP(image1filename, image1);
}


void loadImage2()
{
    char image2filename[100];
    cout << "Enter the source image file name: ";
    cin >> image2filename;
    strcat(image2filename, ".bmp");
    readGSBMP(image2filename, image2);
}


void save_merged_image()
{
    char imagefilename[100];
    cout << "Enter the file you want to save in: ";
    cin >> imagefilename;
    strcat(imagefilename, ".bmp");
    writeGSBMP(imagefilename, merged_image);
}


void filter_b(){
    //this 4 for loops used to separate each quarter from the image in a new image called image2
    for (int i = 0; i < SIZE / 2; ++i ) {
        for (int j = 0; j < SIZE / 2; ++j) {
            image2[i][j] = image[i][j];
        }
        //to separate first quarter.
    }
    for (int i = 0; i < SIZE / 2; ++i) {
        for (int j = SIZE / 2; j < SIZE; ++j) {
            image2[i][j] = image[i][j];
        }
        //to separate second quarter.
    }
    for (int i = SIZE / 2; i < SIZE; ++i) {
        for (int j = 0; j < SIZE / 2; ++j) {
            image2[i][j] = image[i][j];
        }
        //to separate third quarter.
    }
    for (int i = SIZE / 2; i < SIZE; ++i) {
        for (int j = SIZE / 2; j < SIZE; ++j) {
            image2[i][j] = image[i][j];
        }
        //to separate fourth quarter.
    }
    int q[4] ;
    for (int i = 0; i <4 ; ++i) {
        cout << " please enter index " << i <<endl;
        cin >> q[i];
        //this for loop used to take the input from user and know the order which user want to make image.
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
        //this used when the index the user choose is = specific number to go to a function reverse
    }
    //after that we save the new image with new order.
    saveImage2();
}
void reverse1(int choice){
    //reverse1 used to move first quarter in place which user choose.
    int row = 0 , col = 0;
    switch(choice) {
        //switch case to know the user want to move first quarter in which quarter in image2.
        //case 1 : when he want to put first quarter in image1 in first quarter in image2.
        case 1 :
            for (int i = 0; i < SIZE / 2; ++i , ++row ) {
                for (int j = 0; j < SIZE / 2; ++j , ++col) {
                    if(col == SIZE/2){
                        col = 0;
                        //this condition to return colum to zero again after reach end of loop.
                    }
                    image2[i][j] = image[row][col];
                }
            }
            break;

        //case 2 : when he want to put first quarter in image1 in second quarter in image2.
        case 2 :
            for (int i = 0; i < SIZE / 2; ++i , ++row) {
                for (int j = SIZE / 2; j < SIZE; ++j, ++col) {
                    if(col == SIZE/2){
                        col = 0;
                        //this condition to return colum to zero again after reach end of loop.
                    }
                    image2[i][j] = image[row][col];
                }
            }
            break;

        //case 3 : when he want to put first quarter in image1 in third quarter in image2.
        case 3 :
            for (int i = SIZE / 2; i < SIZE; ++i , ++row) {
                for (int j = 0; j < SIZE / 2; ++j , ++col) {
                    if(col == SIZE/2){
                        col = 0;
                    }
                    image2[i][j] = image[row][col];
                }
            }
            break;

        //case 4 : when he want to put first quarter in image1 in fourth quarter in image2.
        case 4 :
            for (int i = SIZE / 2; i < SIZE; ++i , ++row) {
                for (int j = SIZE / 2; j < SIZE; ++j , ++col) {
                    if(col == SIZE/2){
                        col = 0;
                    }
                    image2[i][j] = image[row][col];
                }
            }
            break;
    }
}
void reverse2(int choice){
    //reverse2 used to move second quarter in place which user choose.
    int row = 0 , col = SIZE/2 ;
    switch(choice) {
        //switch case to know the user want to move second quarter in which quarter in image2.
        //case 1 : when he want to put second quarter in image1 in first quarter in image2.
        case 1 :
            for (int i = 0; i < SIZE / 2; ++i , ++row ) {
                for (int j = 0; j < SIZE / 2; ++j , ++col) {
                    if(col == SIZE){
                        col = SIZE/2;
                    }
                    image2[i][j] = image[row][col];
                }
            }
            break;
        //case 2 : when he want to put second quarter in image1 in second quarter in image2.
        case 2 :
            for (int i = 0; i < SIZE / 2; ++i , ++row) {
                for (int j = SIZE / 2; j < SIZE; ++j, ++col) {
                    if(col == SIZE){
                        col = SIZE/2;
                    }
                    image2[i][j] = image[row][col];
                }
            }
            break;
        //case 3 : when he want to put second quarter in image1 in third quarter in image2.
        case 3 :
            for (int i = SIZE / 2; i < SIZE; ++i , ++row) {
                for (int j = 0; j < SIZE / 2; ++j , ++col) {
                    if(col == SIZE){
                        col = SIZE/2;
                    }
                    image2[i][j] = image[row][col];
                }
            }
            break;
        //case 4 : when he want to put second quarter in image1 in fourth quarter in image2.
        case 4 :
            for (int i = SIZE / 2; i < SIZE; ++i , ++row) {
                for (int j = SIZE / 2; j < SIZE; ++j , ++col) {
                    if(col == SIZE){
                        col = SIZE/2;
                    }
                    image2[i][j] = image[row][col];
                }
            }
            break;
    }
}
void reverse3(int choice){
    //reverse1 used to move third quarter in place which user choose.
    int row = SIZE/2 , col = 0 ;
    switch(choice) {
        // switch case to know the user want to move third quarter in which quarter in image2.
        // case 1 : when he want to put third quarter in image1 in first quarter in image2.
        case 1 :
            for (int i = 0; i < SIZE / 2; ++i , ++row ) {
                for (int j = 0; j < SIZE / 2; ++j , ++col) {
                    if(col == SIZE/2){
                        col = 0;
                    }
                    image2[i][j] = image[row][col];
                }
            }
            break;

        // case 2 : when he want to put third quarter in image1 in second quarter in image2.
        case 2 :
            for (int i = 0; i < SIZE / 2; ++i , ++row) {
                for (int j = SIZE / 2; j < SIZE; ++j, ++col) {
                    if(col == SIZE/2){
                        col = 0;
                    }
                    image2[i][j] = image[row][col];
                }
            }
            break;
        //case 3 : when he want to put third quarter in image1 in third quarter in image2.
        case 3 :
            for (int i = SIZE / 2; i < SIZE; ++i , ++row) {
                for (int j = 0; j < SIZE / 2; ++j , ++col) {
                    if(col == SIZE/2){
                        col = 0;
                    }
                    image2[i][j] = image[row][col];
                }
            }
            break;

        //case 4 : when he want to put third quarter in image1 in fourth quarter in image2.
        case 4 :
            for (int i = SIZE / 2; i < SIZE; ++i , ++row) {
                for (int j = SIZE / 2; j < SIZE; ++j , ++col) {
                    if(col == SIZE/2){
                        col = 0;
                    }
                    image2[i][j] = image[row][col];
                }
            }
            break;
    }
}
void reverse4(int choice){
    //reverse1 used to move fourth quarter in place which user choose.
    int row = SIZE/2 , col = SIZE/2;
    switch(choice) {
        //switch case to know the user want to move fourth quarter in which quarter in image2.
        //case 1 : when he want to put fourth quarter in image1 in first quarter in image2.
        case 1 :
            for (int i = 0; i < SIZE / 2; ++i , ++row ) {
                for (int j = 0; j < SIZE / 2; ++j , ++col) {
                    if(col == SIZE){
                        col = SIZE/2;
                    }
                    image2[i][j] = image[row][col];
                }
            }
            break;

        //case 2 : when he want to put fourth quarter in image1 in second quarter in image2.
        case 2 :
            for (int i = 0; i < SIZE / 2; ++i , ++row) {
                for (int j = SIZE / 2; j < SIZE; ++j, ++col) {
                    if(col == SIZE){
                        col = SIZE/2;
                    }
                    image2[i][j] = image[row][col];
                }
            }
            break;

        //case 3 : when he want to put fourth quarter in image1 in third quarter in image2.
        case 3 :
            for (int i = SIZE / 2; i < SIZE; ++i , ++row) {
                for (int j = 0; j < SIZE / 2; ++j , ++col) {
                    if(col == SIZE){
                        col = SIZE/2;
                    }
                    image2[i][j] = image[row][col];
                }
            }
            break;

        //case 4 : when he want to put fourth quarter in image1 in fourth quarter in image2.
        case 4 :
            for (int i = SIZE / 2; i < SIZE; ++i , ++row) {
                for (int j = SIZE / 2; j < SIZE; ++j , ++col) {
                    if(col == SIZE){
                        col = SIZE/2;
                    }
                    image2[i][j] = image[row][col];
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
            // adding adjacent pixels in one pixel
            image[i][j] = (image[i][j] + image[i + 1][j] + image[i][j + 1] + image[i + 1][j + 1] + image[i - 1][j] + image[i][j - 1] + image[i - 1][j - 1] + image[i + 2][j] + image[i][j + 2] + image[i + 2][j + 2] + image[i - 2][j] + image[i][j - 2] + image[i - 2][j - 2] + image[i + 3][j] + image[i][j + 3] + image[i + 3][j + 3] + image[i - 3][j] + image[i][j - 3] + image[i - 3][j - 3]) / 19;
        }
    }
}