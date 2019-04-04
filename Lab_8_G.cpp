/*
Author: Saurav Hossain
Assignment: Lab 8G
Function: Write a program which implements a horizontal edge detection operation. Note: One way to detect horizontal edges is to use the function f(a,b,c,d,e,f,g,h,i) = (g+2h+i)-(a+2b+c).
Date: 04/1/19
Instructor: Panda
File submission name: kernel.cpp
*/

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>

using namespace std;

const int MAX_H = 512;
const int MAX_W = 512;

//borrowed starter code
// Reads a PGM file.
// Notice that: height and width are passed by reference!
void readImage(int image[MAX_H][MAX_W], int &height, int &width)
{
	char c;
	int x;
	ifstream instr;
	instr.open("inImage.pgm");

	// read the header P2
	instr >> c;
	assert(c == 'P');
	instr >> c;
	assert(c == '2');

	// skip the comments (if any)
	while ((instr>>ws).peek() == '#') 
	{
		instr.ignore(4096, '\n');
	}

	instr >> width;
	instr >> height;

	assert(width <= MAX_W);
	assert(height <= MAX_H);
	int max;
	instr >> max;
	assert(max == 255);

	for (int row = 0; row < height; row++)
		for (int col = 0; col < width; col++)
			instr >> image[row][col];
	instr.close();
	return;
}

// Writes a PGM file
// Need to provide the array data and the image dimensions
void writeImage(int image[MAX_H][MAX_W], int height, int width) 
{
	ofstream ostr;
	ostr.open("outImage.pgm");
	if (ostr.fail()) 
	{
		cout << "Unable to write file\n";
		exit(1);
	};

	// print the header
	ostr << "P2" << endl;
	// width, height
	ostr << width << ' ';
	ostr << height << endl;
	ostr << 255 << endl;

	for (int row = 0; row < height; row++) 
	{
		for (int col = 0; col < width; col++) 
		{
			assert(image[row][col] < 256);
			assert(image[row][col] >= 0);
			ostr << image[row][col] << ' ';
			ostr << endl;
		}
	}
	ostr.close();
	return;
}

//rewritten/editted
int main() 
{
    int img[MAX_H][MAX_W];
    int h, w;

    readImage(img, h, w);
    
    int out[MAX_H][MAX_W];

    for (int row = 0; row < h; row ++)
    {
        for (int col = 0; col < w; col ++)
        {
            //This is the f(a,b,c,d,e,f,g,h,i) = (g+2h+i)-(a+2b+c) part and split 2h to h + h 
            int s = (img[row + 1][col - 1] + (img[row + 1][col] + img[row + 1][col]) + img[row + 1][col + 1]) - (img[row - 1][col - 1] + (img[row - 1][col] + img[row - 1][col]) + img[row - 1][col + 1]);
           
			//take care of less and more than
            if (s < 0)
            {
                s = 0;
            }
            else if (s > 255)
            {
                s = 255;
            }
            
            out[row][col] = s;
            
            if (row == 0)
            {
                out[row][col] = 0;
            }
        }
    }
    writeImage(out, h, w);
}