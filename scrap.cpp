/*
Author: Saurav Hossain
Assignment: Project 1B
Function: Write a program that reads from the cin a sequence of one or more non-negative integers written to be added or subtracted. Space characters can be anywhere in the input. After the input ends (end-of-file is reached), the program should compute and print the result of the input summation.
Date: 02/03/19
Instructor: Panda
File submission name: calc.cpp
*/
#include <iostream>
using namespace std;
int main ()
{
  int sum;
  cin >> sum;  // Read the first value as the sum.
  char opr;         // Operator character
  int  value;       // New value or term.
  while (cin >> opr >> value)
  {    
    if(opr == '+')
    { 
      sum += value;
      break;
    }
    else
    {
      sum -= value;
      break;
    }
  }
  cout << sum;
}
