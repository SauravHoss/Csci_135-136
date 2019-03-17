/*
Author: Saurav Hossain
Assignment: Lab 6D
Function: Write a program that uses the above functions to demonstrate encryption and decryption for both ciphers. It should first ask the user to input plaintext, then ask for a right shift for the Caesar cipher and report the ciphertext and its subsequent decryption. After that, it should do the same for the Vigenere cipher.
Date: 03/16/19
Instructor: Panda
File submission name: decryption.cpp
*/

#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

//shifts characters given shift value and a character
char shiftChar(char c, int rshift)
{
  if(rshift < 0)
  {
  	rshift = 26 + rshift;
  }
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

//decrypt caesar 
string decryptCaesar(string ciphertext, int rshift)
{
  rshift = rshift * -1;
  string s = "";
  for(int i = 0; i < ciphertext.length(); i++)
  {
    char c = ciphertext[i];
    s = s + shiftChar(c, rshift);
  }
  return s;
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

//decrypts vigenere
string decryptVigenere(string ciphertext, string keyword)
{
	string s = "";
	int x = 0;
	while(x < ciphertext.length())
	{
		for(int i = 0; i < keyword.length(); i++)
		{			
			if(!isalpha(ciphertext[x]))
			{
				s = s + ciphertext[x];
				i--; //set back cause keyword doesn't change non alpha chars
			}	
			else
			{
				int f = ((int)keyword[i] - 97) * -1;				
				s = s + shiftChar(ciphertext[x], f);
			}
			x++;
			if(x == ciphertext.length())
			{
				break; //hard break out of loop if at last letter
			}			
		}
		if(x == ciphertext.length())
		{
			break; //need a double break because 2 loops
		}	
	}		
	return s;
}

//main
int main() 
{
	string s, k, c, d;
	int x;
		
	//ask for text
	cout << "Enter text: ";
	cin >> s;
/*	
	//prints type and asks for shift
	cout << "=Caesar Encryption=" << endl << "Enter shift: "; 
	cin >> x;
	
	//prints encrypted text
	cout << "Cipher text: " << encryptCaesar(s, x) << endl;
	
	//print reg text
	c = encryptCaesar(s, x);
	cout << "Decrypted text: " << decryptCaesar(c, x) << endl;
*/
	//prints type and asks for keyword
	cout << "=Vigenere=" << endl << "Enter keyword: ";
	cin >> k;
	
	//prints encrypted text
	cout << "Cipher text: " <<  encryptVigenere(s, k) << endl;
	
	//print reg text
	d = encryptVigenere(s, k);
	cout << "Decrypted text: " << decryptVigenere(d, k);
	
	//cout << shiftChar('h' , -20);
}