/*
Author: Saurav Hossain
Date: 05/01/19
Prompt: Write a function that modifies a vector<string>, moving all strings starting with an upper case letter to the front, without otherwise changing the order of the elements.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<string> capSort(vector<string> &v1)
{
  vector<string> vs;
  for(int i = 0; i < v1.size(); i++)
  {
    string s = v1[i];
    if(isupper(s[0]))
    {
      vs.push_back(s);
    }
  }
  for(int i = 0; i < v1.size(); i++)
  {
    string s = v1[i];
    if(!isupper(s[0]))
    {
      vs.push_back(s);
    }
  }
  return vs;
}

int main() 
{
  vector<string> v1{ "Mouse","cat","Dog" };
  
  vector<string>s = capSort(v1);

  for(int i = 0; i < s.size(); i++)
  {
    cout << s[i];
  } 
}