/*
Author: Saurav Hossain
Assignment: Project 2B
Function:Write a program that asks the user to input two integers L and U (representing the lower and upper limits of the interval), and print out all integers in the range L ≤ i < U separated by spaces. Notice that we include the lower limit, but exclude the upper limit.
Date: 02/03/19
Instructor: Panda
File submission name: print-interval.cpp
*/
#include <iostream>
using namespace std;
int main() 
{
  int x,y;
  cin >> x;
  cin >> y;
  for(int i = x; i < y; i++)
  {
    cout << i << " ";
  }
}