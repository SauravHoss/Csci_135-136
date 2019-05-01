/*
Author: Saurav Hossain
Assignment: Lab 12D
Function: Write a program that implements the function vector<int> sumPairWise(vector<int> &v1, vector<int> &v2) that returns a vector of integers whose elements are the pairwise sum of the elements from the two vectors passed as arguments. If a vector has a smaller size that the other, consider extra entries from the shorter vectors as 0. 
Date: 05/1/19
Instructor: Panda
File submission name: pairwise.cpp
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> sumPairWise(vector<int> &v1, vector<int> &v2)
{
  vector<int>sum;
  int s1 = v1.size();
  int s2 = v2.size();

  int x;
  if(s1 > s2)
    {
      x = s1;
    }
  else 
  {
    x = s2;
  }

  if(s1 <= 0) 
    return v2;
  else if(s2 <= 0)
    return v1;
  else
  {
    for(int i = 0; i < x; i++)
    {
      sum.push_back(v1[i] + v2[i]);
    }
    return sum;
    }
}

int main() 
{
  vector<int> v1{1,2,3};
  vector <int> v2{4, 5};
  
  vector<int>s = sumPairWise(v1, v2);

  for(int i = 0; i < s.size(); i++)
  {
    cout << s[i];
  } 
}