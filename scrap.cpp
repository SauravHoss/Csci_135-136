/*
Author: Saurav Hossain
Date: 01/30/19
Prompt: Define a trivial class Triangle that contains three Point members. Write a function that computes the perimeter of a Triangle. Write a program that reads the coordinates of the points, calls your function, and displays the result.
*/

#include <iostream>

using namespace std;

class Point
{
	
	double x, y;
	public: 
		Point(x, y);
};

class Triangle
{
	friend class Point;
	public: 
		Point x, y, z;
	double computePerimeter( )
	{
			
	}

};

int main()
{
	cout << "no error";
}

