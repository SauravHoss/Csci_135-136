/*
Author: Saurav Hossain
Assignment: Lab 4B
Function: Write a program that asks the user to input width and height and prints a rectangular checkerboard of the requested size using asterisks and spaces (alternating).
Date: 02/22/19
Instructor: Panda
File submission name: checkerboard.cpp
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
      if(((i + u) % 2) == 0)
      {
        cout << "*";
      }
      else
        cout << " ";
    }
    cout << endl;
  }
}
