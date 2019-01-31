/*
Author: Saurav Hossain
Assignment: Lab 1B
Function: Write a program that asks the user to input three integer numbers, and prints out the smallest of the three.
Date: 01/30/19
Instructor: Panda
File submission name: smaller3.cpp
*/

#include <iostream>
using namespace std;

int main() 
{
  int x,y,z; 
  cin >> x;
  cin >> y;
  cin >> z;
  
  if(x < y && x < z)
    cout << x;
  else if(z < y && z < x)
    cout << z;
  else
    cout << y;
}