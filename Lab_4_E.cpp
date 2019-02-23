/*
Author: Saurav Hossain
Assignment: Lab 4E
Function: Write a program that prints the top-right half of a square, given the side length.
Date: 02/22/19
Instructor: Panda
File submission name: upper.cpp
*/

#include<iostream>
using namespace std;

int main()
{
  int x;
  cin >> x;
	for(int i = x; i > 0; i--)
	{
		for(int u = 0; u < x - i; u++)
     		cout << " ";
      			for(int u = 1; u <= i; u++)
		 	 {
				cout << "*";
			 }
		cout << endl;
	}
}
