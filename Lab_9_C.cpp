/*
Author: Saurav Hossain
Assignment: Lab 9C
Function: Write a program in which gets the position and the velocity of an object and has to compute object’s new coordinates after the time interval dt. The function does not return any values, instead, it should update the object’s position ppos with its new position coordinates.
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

//main method
int main() 
{
    Coord3D pos = {0, 0, 100.0};
    Coord3D vel = {1, -5, 0.2};

    move(&pos, &vel, 2.0); // object pos gets changed
    cout << pos.x << " " << pos.y << " " << pos.z << endl; // prints: 2 -10 100.4
}

