/*
Author: Saurav Hossain
Date: 05/01/19
Prompt: Write a function vector<int> append(vector<int> a, vector<int> b)that appends one vector after another.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> append(vector<int> a, vector<int> b)
{
  vector<int> s;
  for(int i = 0; i < a.size(); i++)
  {
    s.push_back(a[i]);
  }
  for(int i = 0; i < b.size(); i++)
  {
    s.push_back(b[i]);
  }
  return s;
}

int main() 
{
  vector<int> v1{1,2,3};
  vector<int> v2{4, 5};

  vector<int>s = append(v1, v2);

  for(int i = 0; i < s.size(); i++)
  {
    cout << s[i];
  } 
}