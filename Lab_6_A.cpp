/*
Author: Saurav Hossain
Assignment: Lab 6A
Function: Write a program  that asks the user to input a line of text (which may possibly include spaces). The program should report all characters from the input line together with their ASCII codes. Make sure to print exactly one space between the character and it’s code.
Date: 03/11/19
Instructor: Panda
File submission name: test-ascii.cpp
*/

#include <iostream>
#include <string>
using namespace std;

int main() 
{
  string s;
  getline(cin, s);

  for(int i = 0; i < s.length(); i++)
  {
    cout << s[i] << " " << (int)s[i] << endl;
  }

}
