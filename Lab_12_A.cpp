/*
Author: Saurav Hossain
Assignment: Lab 12A
Function: Program a function called vector<int> makeVector(int n) that returns a vector of n integers that range from 0 to n-1
Date: 05/1/19
Instructor: Panda
File submission name: vectors.cpp
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> makeVector(int n)
{
  vector<int> v;
  for(int i = 0; i < n; i++)
  {
    v.push_back(i);
  }
  return v;
}

int main() 
{
  int n = 5;
  vector <int> f = (makeVector(n));
  for(int i = 0; i < n; i++)
  {
    cout << f[i];
  }
}