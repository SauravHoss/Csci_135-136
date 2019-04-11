/*
Author: Saurav Hossain
Assignment: Lab 9D
Function: Fix this program poem.cpp. It should still keep creating poems, but all dynamically allocated memory should get deleted when it is not needed. (The program can be stopped with Ctrl+C in the terminal.)
Date: 04/8/19
Instructor: Panda
File submission name: poem.cpp
*/

#include <iostream>
using namespace std;

string * createAPoemDynamically() 
{
    string *p = new string;
    *p = "Roses are red, violets are blue";
    return p;
}

int main() 
{
    while(true) 
    {
        string *p;
        p = createAPoemDynamically();

        delete p; // assume that the poem p is not needed at this point
    }
}