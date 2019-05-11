/*
Author: Saurav Hossain
Assignment: Lab 13A
Function: Write a program defining a function void printRange(int left, int right); that prints all numbers in range left ≤   x   ≤ right, separated by spaces. (Don’t use loops, global or static variables.
Date: 05/08/19
Instructor: Panda
File submission name: recursion.cpp
*/

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

int main() 
{
  printRange(-2, 10);
}

