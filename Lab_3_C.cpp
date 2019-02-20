/*
Author: Saurav Hossain
Assignment: Lab 3C
Function: Write a program that asks the user to input two dates (the beginning and the end of the interval). The program should check each day in the interval and report which basin had higher elevation on that day by printing “East” or “West”, or print “Equal” if both basins are at the same level.
Date: 02/17/19
Instructor: Panda
File submission name: compare.cpp
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
   
  ifstream fin("Current_Reservoir_Levels.tsv");
  if (fin.fail())
  {
    cerr << "File cannot be opened for reading."<< endl;
    exit(1);
  }
  
  string junk, date;
  float eastSt, eastEl, westSt, westEl;
  getline(fin, junk);

  bool t = false;
  while (fin >> date >> eastSt >> eastEl >> westSt >> westEl)
  {
    fin.ignore(INT_MAX, '\n');
  
  	if(sd.compare(date) == 0)
  	{
  		t = true;
  	}
  	if(t)
  	{
  		cout << date;
  		if(eastEl > westEl)
  		{
  			cout << " East " << endl;
  		}
  		else if(westEl > eastEl)
  		{
  			cout << " West " << endl;
  		}
  		else
  		{
  			cout << " Equal " << endl;
  		}
  	}
  	if(ed.compare(date) == 0)
  	{
  		t = false;
  	}
  	
  }
  fin.close();
}
