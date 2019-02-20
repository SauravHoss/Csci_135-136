/*
Author: Saurav Hossain
Assignment: Lab 3B
Function: Write a program that finds the minimum and maximum storage in East basin in 2018.
Date: 02/17/19
Instructor: Panda
File submission name: minmax.cpp
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>

using namespace std;

int main()
{
	ifstream fin("Current_Reservoir_Levels.tsv");
	if (fin.fail())
	{
   		cerr << "File cannot be opened for reading."<< endl;
    		exit(1);
	}
	
  	string junk, date;
  	double eastSt, eastEl, westSt, westEl, min = INT_MAX, max = INT_MIN;
  	
  	getline(fin, junk);
  	
  	while (fin >> date >> eastSt >> eastEl >> westSt >> westEl)
  	{
    	fin.ignore(INT_MAX, '\n');
   		if(eastSt <= min)
   		{
      			min = eastSt;
    		}
   		if(eastSt >= max)
   		{
      			max = eastSt;
    		}
  	}
 	cout << "minimum storage in East Basin: " << min << endl << "maximum storage in East Basin: " << max << endl;
  	fin.close();
}
