/*
Author: Saurav Hossain
Assignment: Lab 12B
Function: Write a program called that implements the function vector<int> goodVibes(vector<int> v); that, given a vector of integers, returns a vector with only the positive integers in the same order.
Date: 05/1/19
Instructor: Panda
File submission name:  optimism.cpp
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> goodVibes(vector<int> v)
{
  vector<int> f;
  for(int i = 0; i < v.size(); i++)
  {
    if(v[i] >= 0)
    {
      f.push_back(v[i]);
    }
  }
  return f;
}

int main() 
{
  vector<int> v{1,2,-1,3,4,5,-1,6};
  vector <int> g = goodVibes(v);
  
  for(int i = 0; i < g.size(); i++)
  {
    cout << g[i];
  } 
}
