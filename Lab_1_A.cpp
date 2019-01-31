/*
Author: Saurav Hossain
Assignment: Lab 1A
Function: Write a program that asks the user to input two integer numbers and prints out the smaller of the two.
Date: 01/30/19
Instructor: Panda
File submission name: smaller.cpp
*/

#include <iostream>
using namespace std;

int main() 
{
  int x,y; 
  cin >> x;
  cin >> y;
  
  if(x > y)
    cout << y;
  else
    cout << x;
}