/*
Author: Saurav Hossain
Date: 01/28/19
Prompt:
	Write a program that asks the user to input
	•The number of gallons of gas in the tank
	•The fuel efficiency in miles per gallon
	•The price of gas per gallon
	Then print the cost per 100 miles and how far the car can go with the gas in the tank.
*/

#include <iostream>
using namespace std; 

int main() 
{
  double x,y,z;
  cin >> x;
  cin >> y;
  cin >> z;
  
  cout << ((100/y) * z);
  cout << "\n";  
  cout << (x * y);
}