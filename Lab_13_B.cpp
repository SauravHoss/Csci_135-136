/*
Author: Saurav Hossain
Assignment: Lab 13B
Function: Write a program defining a function int sumRange(int left, int right); that computes the sum of all numbers in range left ≤   x   ≤ right. (Don’t use loops, global or static variables.)
Date: 05/08/19
Instructor: Panda
File submission name: recursion.cpp
*/

//here's your one comment

#include <iostream>
using namespace std;

void printRange(int left, int right)
{
  if(left > right)
  {
    return;
  }
  else
  {
    cout << left << endl;
    printRange(left + 1, right);
  }
}

int sumRange(int left, int right)
{
  int sum = 0;
  if(left > right)
    return sum;
  else
  {
   return sum = left + sumRange(left + 1, right);
  }
}

int main() 
{
  cout << sumRange(-1, 3);
}
