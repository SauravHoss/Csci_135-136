/*
Author: Saurav Hossain
Assignment: Lab 13E
Function: Write a program defining a function bool nestedParens(string s); which returns true if the string is a sequence of nested parentheses: Strings "", "()", "(())", "((()))" … are all correct sequences and should return true. Any other symbols or mismatching parenthesis should make the function return false.
Date: 05/10/19
Instructor: Panda
File submission name: recursion.cpp
*/

#include <iostream>
#include <string>
using namespace std;

void printRange(int left, int right)
{
  if(left > right)
  {
    return;
  }
  else
  {
    cout << left << endl;
    printRange(left + 1, right);
  }
}

int sumRange(int left, int right)
{
  int sum = 0;
  if(left > right)
    return sum;
  else
  {
   return sum = left + sumRange(left + 1, right);
  }
}

int sumArrayInRange(int *arr, int left, int right)
{
  int sum = 0;
  if(left > right)
    return sum;
  else
  {
    return sum = arr[left] + sumArrayInRange(arr, left + 1, right);
  }
}

int sumArray(int *arr, int size)
{
  int sum = 0;
  if(size <= 0)
    return sum;
  else
  {
    return sumArrayInRange(arr, 0, size-1);
  }
}

bool isAlphanumeric(string s)
{
  if(s.length() <= 0)
    return true;
  else
  {
    if((((int)s[0]) >= 48 && ((int)s[0]) <= 57) || (((int)s[0]) >= 65 && ((int)s[0]) <= 90) || (((int)s[0]) >= 97 && ((int)s[0]) <= 122))
    {
      return isAlphanumeric(s.substr(1));
    }
    else
      return false;
  }
}

bool nestedParens(string s)
{
  if(s.length() <= 0)
    return true;
  else
  {
    if((int)s[0] == 40)
    {
      if((int)s[s.length() - 1] == 41)
      {
        return nestedParens(s.substr(1, s.length()-2));
      }
      else
        return false;
    }
    else
      return false;
  }
}

int main() 
{
  cout << nestedParens("((()))") << endl;      // true (1)
  cout << nestedParens("()") << endl;          // true (1)
  cout << nestedParens("") << endl;            // true (1)
  
  cout << nestedParens("(((") << endl;         // false (0)
  cout << nestedParens("(()") << endl;         // false (0)
  cout << nestedParens(")(") << endl;          // false (0)
  cout << nestedParens("a(b)c") << endl;       // false (0)
}