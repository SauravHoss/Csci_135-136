/*
Author: Saurav Hossain
Date: 02/22/19
Prompt: Write a program that asks the user for an integer, and prints whether it is negative, positive, or zero.
*/
#include <iostream>
using namespace std;

int main() 
{
  int x;
  cin >> x;

  if(x > 0)
    cout << "Positive";
  else if(x < 0)
    cout << "Negative";
  else
    cout << "Zero";
}
