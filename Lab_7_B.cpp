/*
Author: Saurav Hossain
Assignment: Lab 7B
Function: Write a new program that enhances the program from the previous task. As it reads the input line by line, it should also count the number of open and closed { } in it, and keep track of how many blocks is currently open at the beginning of each line, add that number of tabs '\t' at the beginning of each line.
Date: 03/26/19
Instructor: Panda
File submission name: indent.cpp
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

//counts the number of characters in a line
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

//indents line given line and number of tabs to put in
string indenter(string x, int y)
{
    string t = "";
    for(int i = 0; i < y; i++)
    {
        t += "\t";
    }
    return (t + x);
}

//main method
int main()
{
    string line = "";
    int tabs = 0;

    while(getline(cin, line))
    {
        if(removeLeadingSpaces(line)[0] == '}')
        {
            cout << indenter(removeLeadingSpaces(line), tabs - 1) << endl;
		}
        else
        {
            cout << indenter(removeLeadingSpaces(line), tabs) << endl;
		}
        
        tabs += countChar(line, '{');
        tabs -= countChar(line, '}');
    }
}