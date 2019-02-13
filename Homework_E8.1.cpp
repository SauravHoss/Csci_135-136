/*
Author: Saurav Hossain
Date: 01/30/19
Prompt: Write a program that carries out the following tasks:
      Open a file with the name hello.txt.
      Store the message “Hello, World!” in the file.
      Close the file.
      Open the same file again.
      Read the message into a string variable and print it.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main ()
{
	ofstream outFile;
	outFile.open("hello.txt");

	outFile << "Hello, World!" << endl;

	outFile.close();

	ifstream inFile; 
	inFile.open("hello.txt");
	
	string s,v;	

	inFile >> s >> v;
	cout << s << " " << v;	
}
