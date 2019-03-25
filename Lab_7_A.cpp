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

//main method
int main()
{
    string s;
    while (getline(cin, s))
    {
        cout << removeLeadingSpaces(s) << endl;
    }
}