/*
Author: Saurav Hossain
Assignment: Lab 3A
Function: Write a program east-storage.cpp that asks the user to input a string representing the date (in MM/DD/YYYY format), and prints out the East basin storage on that day.
Date: 02/17/19
Instructor: Panda
File submission name: east-storage.cpp
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

using namespace std;

int main() 
{	
	string junk, date, eastSt, eastEl, westSt, westEl, datein;
	cin >> datein;
	ifstream fin("Current_Reservoir_Levels.tsv");
	if (fin.fail()) 
	{
   		cerr << "File cannot be opened for reading." << endl;
   		exit(1); // exit if failed to open the file
	}
	

	getline(fin, junk); // read one line from the file 
	
	while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) 
	{ 
    // this loop reads the file line-by-line
    // extracting 5 values on each iteration 
    
    fin.ignore(INT_MAX, '\n'); //skips to the end of line, 
                          //ignorring the remaining columns 

    
    	if(datein.compare(date)==0)
    	{
    		cout << "East basin storage: " << eastSt;
    	}
	}
	fin.close();
}