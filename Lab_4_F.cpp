/*
Author: Saurav Hossain
Assignment: Lab 4F
Function: Write a program that prints an upside-down trapezoid of given width and height.
Date: 02/22/19
Instructor: Panda
File submission name: trapezoid.cpp 
*/

#include <iostream>
using namespace std;
int main() 
{
  int x,y, sp = 0;
  cin >> x;
  cin >> y;

  if(((y * 2) - 1) > x)
	{
		cout << "Impossible Shape!";	
	}
  else
  {
    while(x > 0)
    {
      if(sp == y)
      {
        break;
      }
      for(int i = 0; i < sp; i++)
      {
        cout << " ";
      }
      for(int i = 0; i < x; i++)
      {
        cout << "*";
      }
      cout << endl;
      x = x - 2;
      sp++; 
    }
  }
}