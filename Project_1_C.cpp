/*
Author: Saurav Hossain
Assignment: Project 1C
Function: Write a better version of the calculator that can evaluate multiple arithmetic expressions. Let’s use the semicolon symbol that must be used at the end of each expression in the input.
Date: 02/03/19
Instructor: Panda
File submission name: calc2.cpp
*/
#include <iostream>
using namespace std;
int main ()
{

  int x,v;
  cin >> x;
  char o;
  while (cin >> o >> v)
  {    
    if(o == '+')
    { 
      x += v;	
    }
    else if(o == '-')
    {
      x -= v;
    }
    else
    {
      cout << x << endl;
      x = v;
    }
    
  }
  cout << x;
}
