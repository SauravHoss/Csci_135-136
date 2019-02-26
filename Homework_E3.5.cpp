/*
Author: Saurav Hossain
Date: 02/26/19
Prompt: Write a program that reads three numbers and prints “increasing” if they are in increasing order, “decreasing” if they are in decreasing order, and “neither” otherwise.
Here, “increasing” means “strictly increasing”, with each value larger than its predecessor. The sequence 3 4 4 would not be considered increasing.
*/
#include <iostream>
using namespace std;

int main() 
{
  int x, y ,z;
  cin >> z >> y >> x;

  if(x > y && y > z)
  {
    cout << "Increasing";
  } 
  else if(x < y && y < z)
  {
    cout << "Decreasing";
  }
  else
    cout << "Neither";
}