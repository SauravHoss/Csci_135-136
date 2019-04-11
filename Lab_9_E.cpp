/*
Author: Saurav Hossain
Assignment: Lab 9E
Function: Write a program that adds functions that create, delete, and coordinate objects dynamically
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

//updates ppos to match movement 
void move(Coord3D *ppos, Coord3D *pvel, double dt)
{
	(*ppos).x += ((*pvel).x * dt); //update x
	(*ppos).y += ((*pvel).y * dt); //update y
	(*ppos).z += ((*pvel).z * dt); //update z
}

// allocate memory and initialize
Coord3D* createCoord3D(double x, double y, double z)
{
	Coord3D * co = new Coord3D;
	(*co).x = x;
	(*co).y = y;
	(*co).z = z;
	
	return co;
	
}

// free memory
void deleteCoord3D(Coord3D *p)
{
	delete p;
}

//main method
int main() 
{
    double x, y, z;
    cout << "Enter position: ";
    cin >> x >> y >> z;
    Coord3D *ppos = createCoord3D(x,y,z);
    
    cout << "Enter velocity: ";
    cin >> x >> y >> z;
    Coord3D *pvel = createCoord3D(x,y,z);

    move(ppos, pvel, 10.0);

    cout << "Coordinates after 10 seconds: " 
         << (*ppos).x << " " << (*ppos).y << " " << (*ppos).z << endl;

    deleteCoord3D(ppos); // release memory
    deleteCoord3D(pvel);
}