/*
Author: Saurav Hossain
Assignment: Lab 1D
Function: Write a program that asks the user to input the year and the month (1-12) and prints the number of days in that month (taking into account leap years). You may not use switch case or arrays even if you know these language constructs.
Date: 01/30/19
Instructor: Panda
File submission name: month.cpp
*/

#include <iostream>
using namespace std; 

bool leap(int x) 
{
  if(x % 4 != 0)
    return false;
  else if(x % 100 != 0)
    return true;
  else if(x % 400 != 0)
    return false;
  else
    return true;
}

int main()
{
  int i,u;
  cin >> i;
  cin >> u;
  bool x = leap(i);
  if(x == true && u == 2)
    cout << "29";
  else if(x == false && u == 2)
    cout << "28";
  else if( u == 1 || u == 3 || u == 5 || u == 7 || u == 8 || u == 10 || u == 12 )
    cout << "31";
  else
    cout << "30";
}