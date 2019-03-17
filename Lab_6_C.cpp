/*
Author: Saurav Hossain
Assignment: Lab 6C
Function: Write a program that should contain a function encryptVigenere implementing this cipher: string encryptVigenere(string plaintext, string keyword); You may assume that the keyword contains only lowercase alphabetic characters a - z.
Date: 03/16/19
Instructor: Panda
File submission name: vigenere.cpp
*/

#include <iostream>
#include <string>
#include <stdio.h>
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

//encrypts given text and a keyword
string encryptVigenere(string plaintext, string keyword)
{
	string s = "";
	int x = 0;
	while(x < plaintext.length())
	{
		for(int i = 0; i < keyword.length(); i++)
		{			
			if(!isalpha(plaintext[x]))
			{
				s = s + plaintext[x];
				i--; //set back cause keyword doesn't change non alpha chars
			}	
			else
			{
				int f = (int)keyword[i] - 97;				
				s = s + shiftChar(plaintext[x], f);
			}
			x++;
			if(x == plaintext.length())
			{
				break; //hard break out of loop if at last letter
			}			
		}
		if(x == plaintext.length())
		{
			break; //need a double break because 2 loops
		}	
	}		
	return s;
}

//main
int main() 
{
  cout << encryptVigenere("Hello, World!", "cake");
}
