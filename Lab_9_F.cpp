/*
Author: Saurav Hossain
Assignment: Lab 9F
Function: Write a program that should declare a new class Particle, which stores position and velocity of the particle, and provides the following programming interface:
Particle* createParticle(double x, double y, double z, double vx, double vy, double vz);
void setVelocity(Particle *p, double vx, double vy, double vz);
Coord3D getPosition(Particle *p);
void move(Particle *p, double dt);
void deleteParticle(Particle *p);
Date: 04/11/19
Instructor: Panda
File submission name: particle.cpp
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

class Particle
{
	public:
		double x;
		double y;
		double z;
		
		double vx;
		double vy;
		double vz;
};

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

// dynamically allocate memory for a particle and initialize it
Particle* createParticle(double x, double y, double z, double vx, double vy, double vz)
{
	Particle * pp = new Particle;
	
	(*pp).x = x;
	(*pp).y = y;
	(*pp).z = z;
	(*pp).vx = vx;
	(*pp).vy = vy;
	(*pp).vz = vz;
	
	return pp;
}

// delete all memory allocated for the particle passed by pointer
void deleteParticle(Particle *p)
{
	delete p;
}

// get its current position
Coord3D getPosition(Particle *p)
{
	Coord3D coors; 
	
	coors.x = (*p).x;
	coors.y = (*p).y;
	coors.z = (*p).z;
	
	return coors;	
}

// set its velocity to (vx, vy, vz)
void setVelocity(Particle *p, double vx, double vy, double vz)
{
	(*p).vx = vx;
	(*p).vy = vy;
	(*p).vz = vz;
}

// update particle's position after elapsed time dt
void move(Particle *p, double dt)
{
	(*p).x += (*p).vx * dt;
	(*p).y += (*p).vy * dt;
	(*p).z += (*p).vz * dt;
}

int main() 
{
    // make new particle
    Particle *p = createParticle(1.0, 1.5, 2.0, 0.1, 0.2, 0.3);
    double time = 0.0;
    double dt = 0.1;
    
    while(time < 3.0) 
    {
        // update its velocity
        setVelocity(p, 10.0 * time, 0.3, 0.1);

        // move the particle
        move(p, dt);
        time += dt;

        // reporting its coordinates
        cout << "Time: " << time << " \t";
        cout << "Position: " << getPosition(p).x << ", " << getPosition(p).y << ", " << getPosition(p).z << endl;
    }
    
    // remove the particle, deallocating its memory
    deleteParticle(p);
}