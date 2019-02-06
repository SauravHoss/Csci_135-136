/*
Author: Saurav Hossain
Assignment: Project 2A
Function:Write a program, which asks the user to input an integer in the range 0 < n < 100. If the number is out of range, the program should keep asking to re-enter until a valid number is input.
Date: 02/03/19
Instructor: Panda
File submission name: valid.cpp
*/
#include <iostream>
using namespace std;
int main() 
{
  int x;
  cout << "Enter a number between 0 and 100\n";
  cin >> x;
  while(x <= 0 || x >= 100)
  {
    cout << "Enter a number between 0 and 100\n";
    cin >> x;
  }
    cout << "The number squared is " << (x*x); 
}