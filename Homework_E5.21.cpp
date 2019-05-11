/*
Author: Saurav Hossain
Date: 05/10/19
Prompt: Write a recursive function string reverse(string str); that computes the reverse of a string. For example, reverse("flow") should return "wolf". 

Hint: Reverse the substring starting at the second character, then add the first character at the end. For example, to reverse "flow", first reverse "low" to "wol", then add the "f" at the end.
*/

#include <iostream>
#include <string>
using namespace std; 

string reverse(string str)
{
  if (str.length() == 1) 
  {
    return str;
  }
  else
  {
    return reverse(str.substr(1, str.length())) + str.at(0);
  }
}

int main()
{
  string str = "wolf";
  cout << reverse(str);
}