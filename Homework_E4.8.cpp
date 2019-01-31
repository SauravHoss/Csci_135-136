/*
Author: Saurav Hossain
Date: 01/30/19
Prompt: Write a program that reads a word and prints each character of the word on a separate line. For example, if the user provides the input "Harry", the program prints:
H
a
r
r
y
*/

#include <iostream>
using namespace std; 

int main()
{
  string x;
  cin >> x;

  for(int i = 0; i < x.length(); i++)
  {
    cout << x.substr(i, 1) + "\n";
  }
}