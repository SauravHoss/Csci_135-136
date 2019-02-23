/*
Author: Saurav Hossain
Assignment: Lab 4A
Function: Write a program that asks the user to input width and height and prints a solid rectangular box of the requested size using asterisks.
Date: 02/22/19
Instructor: Panda
File submission name: box.cpp
*/

#include <iostream>
using namespace std;
int main() 
{
  int x,y;
  cin >> x;
  cin >> y;
  cout << "Shape: " << endl;
  for(int i = 0; i < y; i++)
  {
    for(int u = 0; u < x; u++)
    {
      cout << "*";
    }
    cout << endl;
  }
}