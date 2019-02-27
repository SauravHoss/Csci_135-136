/*
Author: Saurav Hossain
Date: 02/26/19
Prompt: Write a function that computes the balance of a bank account with a given initial balance and interest rate, after a given number of years. Assume interest is compounded yearly.
*/
#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
  double x, y, z, a;
  cin >> x;
  cin >> y; 
  cin >> z;

  a = x * pow((1 + (y/100)), z);
  
  cout << a << endl;
}
