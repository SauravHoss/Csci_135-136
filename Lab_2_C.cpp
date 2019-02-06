/*
Author: Saurav Hossain
Assignment: Project 2C
Function:Write a program that creates an array of 10 integers, and provides the user with an interface to edit any of its elements.
Date: 02/03/19
Instructor: Panda
File submission name: edit-array.cpp
*/
#include <iostream>
using namespace std;
int main ()
{
  int myData[10] = {1};
  for (int n = 0; n < 10; n++)
    {
      myData[n] = 1;
    }
  int x,y;
  do
  {
    for (int n = 0; n < 10; n++)
    {
      cout << myData[n] << " ";
    }

    cout << "\n";
    cin >> x;
    cin >> y;
    if(x >= 0 && x < 10)
      myData[x] = y;
    else
      break;
  }
  while(x >= 0 && x < 10);
  cout << "Exit.";  
}