/*
Author: Saurav Hossain
Assignment: Lab 7A
Function: Write a program that reads input from cin and prints out each input line with leading spaces removed.
Date: 03/24/19
Instructor: Panda
File submission name: unindent.cpp
*/

#include <iostream>
#include <cctype>
#include <string>
#include <fstream>
using namespace std;

//removes beginning space
string removeLeadingSpaces(string line)
{
    int x = 0;
    for (int i = 0; i < line.length(); i++)
    {
        if (isspace(line[i]))
        {
            x++;
        }
        else
        {
            break;
        }
    }
    return line.substr(x);
}

int countChar(string line, char c)
{
	int x = 0;
	for(int i = 0; i < line.length(); i++)
	{
		if(line[i] == c)
		{
			x++;
		}
	}
	return x;
}

//main method
int main()
{
    string s;
    string t;
    
    while (getline(cin, s))
    { 	
    	//tab printer
		for(int i = 0; i < countChar(s, '{'); i++)
		{
			t = t + '\t';
		}
		for(int i = 0; i < countChar(s, '}'); i++)
		{
			t = t.substr(t.length());
			//cout << "flag";
		}
		cout << removeLeadingSpaces(s) << endl;
		cout << t;       
		//cout << countChar(s, '{') << countChar(s, '}');
    }    
}
