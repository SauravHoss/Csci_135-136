/*
Author: Saurav Hossain
Assignment: Lab 9A
Function: Write a program in which you define a function length() that receives the coordinates of a point P passed as a pointer, and computes the distance from the origin to the point P.
Date: 04/8/19
Instructor: Panda
File submission name: 3d-space.cpp
*/

#include <iostream>
#include <cmath>

using namespace std;

//class with x,y,z coordinate
class Coord3D 
{
	public:
		double x;
    	double y;
    	double z;
};

//calculates distance from (0,0,0)
double length(Coord3D *p)
{
	return sqrt( (pow((*p).x, 2)) + (pow((*p).y, 2)) + (pow((*p).z, 2)) );
}

//main method
int main() 
{
    Coord3D pointP = {10, 20, 30};
    cout << length(&pointP) << endl; // would print 37.4166
}