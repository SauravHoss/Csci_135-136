/*
Author: Saurav Hossain
Assignment: Lab 2D
Function: Write a program which uses an array of ints to compute and print all Fibonacci numbers from F(0) to F(59).
Date: 02/03/19
Instructor: Panda
File submission name: fibonacci.cpp
*/

#include <iostream>
using namespace std;

int main ()
{
  int fib[60] = {0,1};  

  for(int i = 2; i < 60 ; i++)
  {
    fib[i] = fib[i-2] + fib[i-1];
  }

  for(int i = 0; i < 60; i++)
  {
    cout << fib[i] << "\n";
  }
}
