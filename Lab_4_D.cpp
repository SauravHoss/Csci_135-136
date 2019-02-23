/*
Author: Saurav Hossain
Assignment: Lab 4D
Function: Write a program that prints the bottom-left half of a square, given the side length.
Date: 02/22/19
Instructor: Panda
File submission name: lower.cpp
*/

#include <iostream>
using namespace std;
int main() 
{
  int x;
  cin >> x;
  cout << "Shape: " << endl;
  for(int i = 0; i <= x; i++)
  {
    for(int u = 0;u < i; u++)
    {
      cout << "*";
    }
  cout << endl;
  }
}