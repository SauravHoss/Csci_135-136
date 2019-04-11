/*
Author: Saurav Hossain
Assignment: Lab 9B
Function: Write a program which receives the coordinates of two points (passed as pointers), and returns the pointer of the point that is farther away from the origin.
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

//returns which one is further 
Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2)
{
	if(length(p1) > length(p2)) // senses for which one is bigger
		return p1; // if first return first
	else
		return p2; // else second 
}

//main method
int main() 
{
    Coord3D pointP = {10, 20, 30};
    Coord3D pointQ = {-20, 21, -22};

    cout << "Address of P: " << &pointP << endl;
    cout << "Address of Q: " << &pointQ << endl << endl;

	Coord3D * ans = fartherFromOrigin(&pointP, &pointQ);
   
	cout << "ans = " << ans << endl; // So which point is farther?
}
