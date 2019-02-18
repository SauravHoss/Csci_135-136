/*
Author: Saurav Hossain
Assignment: Project 1D
Function: Write an even better calculator program that can understand squared numbers. We are going to use a simplified notation X^ to mean X2. For example, 10^ + 7 - 51^ should mean 102 + 7 − 512.
Date: 02/17/19
Instructor: Panda
File submission name: calc3.cpp
*/

#include <iostream>
using namespace std;

int main() 
{	
	int temp = 0, sum = 0;
	char cp; // current operation
	char pp = '+'; // previous operation without '+' '^' no work
	cin >> temp;
	
	while (cin >> cp) 
	{ 		
		if(cp == '^')
		{
			temp = temp * temp;
			cin >> cp;
		}
		if(pp == '+')
		{
			sum += temp;
		} 
		else if(pp == '-')
		{
			sum -= temp;
		}
		
		pp = cp;
		cin >> temp;
		
		if(pp == ';')
		{
			cout << sum << endl;
			sum = 0;
			pp = '+';
		}
	}
}