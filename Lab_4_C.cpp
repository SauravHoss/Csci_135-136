/*
Author: Saurav Hossain
Assignment: Lab 4C
Function: Write a program that asks the user to input the shape size, and prints a diagonal cross of that dimension.
Date: 02/22/19
Instructor: Panda
File submission name: cross.cpp
*/

#include <iostream>
using namespace std;
int main() 
{
  int x;
  cin >> x;
  cout << "Shape: " << endl;
  for(int i = 1; i <= x; i++)
  {
    for(int u = 1;u <= x; u++)
    {
      if((i == u) || (u == (x + 1) - i))
      {
        cout << "*";
      }
      else 
        cout << " ";
    }
  cout << endl;
  }
}