/*
Author: Saurav Hossain
Assignment: Lab 1C
Function: Write a program that asks the user to input an integer representing a year number (1999, 2016, etc.). If the input year is a leap year according to the modern Gregorian calendar, it should print Leap year, otherwise, print Common year.
Date: 01/30/19
Instructor: Panda
File submission name: leap.cpp
*/

#include <iostream>
using namespace std;

int main() 
{
  int x;
  cin >> x;
  if(x % 4 != 0)
    cout << "Common Year";
  else if(x % 100 != 0)
    cout << "Leap Year";
  else if(x % 400 != 0)
    cout << "Common Year";
  else
    cout << "Leap Year";
}