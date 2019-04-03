/*
Author: Saurav Hossain
Assignment: Lab 8E
Function: Write a program that scales the original picture to 200% of its size. It can be done by increasing the size of the picture by the factor of 2, and copying each pixel of the input as a small 2x2 square in the output.
Date: 04/1/19
Instructor: Panda
File submission name: scale.cpp
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

	for(int row = 0; row < h; row++) 
	{
		for(int col = 0; col < w; col++) 
		{
			out[row * 2][col * 2] = img[row][col];
			out[row * 2 + 1][col * 2] = img[row][col];
			out[row * 2][col * 2 + 1] = img[row][col];
			out[row * 2 + 1][col * 2 +1] = img[row][col];
		}
	}
	writeImage(out, 2 * h, 2 * w);
}