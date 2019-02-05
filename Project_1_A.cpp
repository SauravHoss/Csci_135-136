/*
Author: Saurav Hossain
Assignment: Project 1A
Function: Write a program that reads a sequence of integers from cin, and reports their sum.
Date: 02/03/19
Instructor: Panda
File submission name: sum.cpp
*/
#include <iostream>
using namespace std;
int main() 
{
  int s;
  int x = 0;
  while(cin >> s) 
  {
    x = s + x;
  }
  cout << x;
}