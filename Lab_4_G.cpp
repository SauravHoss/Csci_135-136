/*
Author: Saurav Hossain
Assignment: Lab 4G
Function: Write a program that asks the user to input width and height and prints a checkerboard of 3-by-3 squares. (It should work even if the input dimensions are not a multiple of three.)
Date: 02/22/19
Instructor: Panda
File submission name: checkerboard3x3.cpp
*/
#include <iostream>
using namespace std;

int main() 
{
  int x,y; 
  cin >> x;
  cin >> y;
  
  string res = "";
    for (int i = 0; i < y; i++) 
    {
      for (int j = 0, c = '*'; j < x; j++, c = '*') 
      {
        if(((j / 3) & 1) ^ ((i / 3) & 1)) // ^ is exclusive or damn i missed DE
          c = ' ';
          res += (char)c;
      }
      res += '\n';
    }
    cout << res;
}