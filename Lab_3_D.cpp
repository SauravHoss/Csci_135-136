/*
Author: Saurav Hossain
Assignment: Lab 3D
Function: Write a program which asks the user to input two dates (earlier date then later date). The program should report the West basin elevation for all days in the interval in the reverse chronological order (from the later date to the earlier).
Date: 02/17/19
Instructor: Panda
File submission name: reverse-order.cpp 
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>

using namespace std;

int main()
{
	string sd, ed;
	cin >> sd;
	cin >> ed;
	
	//just reading in file
	ifstream fin("Current_Reservoir_Levels.tsv");
	if (fin.fail())
	{
   		cerr << "File cannot be opened for reading."<< endl;
    		exit(1);
	}
	
  	string junk, date;
  	double eastSt, eastEl, westSt, westEl, min = INT_MAX, max = INT_MIN;
  	
  	//two pre-set arrays because max data is a year, 370 gives about 5 more spaces than needed
  	double arrwestEl[370];
  	string arrdates[370];
  	
  	getline(fin, junk);
  	
  	//shove them into the array 
  	int u = 0;
  	while (fin >> date >> eastSt >> eastEl >> westSt >> westEl)
  	{
    	fin.ignore(INT_MAX, '\n');
   			
   			arrwestEl[u] = westEl;
   			arrdates [u] = date;
   			u++;   		   			
  	}
  	
  	bool t = false;
  	
  	for(int i = 369; i >= 0; i--)
  	{
  		if(ed.compare(arrdates[i]) == 0)
  		{
  			t = true;
  		}
  		if(t)
  		{
			cout << arrdates[i] << " " << arrwestEl[i] << endl;		
  		}	
  		if(sd.compare(arrdates[i]) == 0)
  		{
  			t = false;
  		}  		
  	}	
  	fin.close();
}