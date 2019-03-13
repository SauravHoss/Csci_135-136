/*
Author: Saurav Hossain
Assignment: Lab 6B
Function: Write a program with functions implementing Caesar cipher encryption
Date: 03/11/19
Instructor: Panda
File submission name: caesar.cpp
*/

#include <iostream>
#include <string>
using namespace std;

//shifts characters given shift value and a character
char shiftChar(char c, int rshift)
{
  char r;
  if(isalpha(c))
  {
    if((int)c <= 122 && (int)c >= 97 )
    {
      if(((int)c + rshift) > 122)
      {
        int x = ((int)c + rshift) - 122;
        r = 96 + x;
      } 
      else
        r = (int)c + rshift;
    }
    else if((int)c <= 90 && (int)c >= 65 )
    {
      if(((int)c + rshift) > 90)
      {
        int x = ((int)c + rshift) - 90;
        r = 64 + x;
      } 
      else
        r = (int)c + rshift;
    }
  }
  else
  {
    r = c;
  }
  return r;
}

//encrypts text given shift value 
string encryptCaesar(string plaintext, int rshift)
{
  string s = "";
  for(int i = 0; i < plaintext.length(); i++)
  {
    char c = plaintext[i];
    s = s + shiftChar(c, rshift);
  }
  return s;
}

int main() 
{
//  cout << shiftChar('v', 7);
  cout << encryptCaesar("Hello, World!", 10);
}
