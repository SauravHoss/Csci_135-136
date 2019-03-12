/*
Author: Saurav Hossain
Assignment: Project 2A
Function: Write a program that reads a text file called dna.txt that contains one DNA strand per line and outputs to the console (terminal) the corresponding mRNA strands.
Date: 03/11/19
Instructor: Panda
File submission name: transcriptase.cpp
*/
#include <iostream>
#include <fstream>
#include <string> 
#include <cstdlib>
using namespace std;

//converts the char
char DNAbase_to_mRNAbase(char v)
{
	char c = toupper(v);
	
	if(c == 'A')
	{
		return 'U';
	}
	else if(c == 'T')
	{
		return 'A'; 
	}
	else if(c == 'C')
	{
		return 'G';
	}
	else
	{
		return 'C';
	}
}

//iterates for the string 
string DNA_to_mRNA(string s)
{
	string f;
	for(int i = 0; i < s.length(); i++)
	{
		f = f + DNAbase_to_mRNAbase(s[i]);
	}
	return f;
}

//main method 
int main()
{
	ifstream fin("dna.txt");
	if(fin.fail()) 
	{
		cerr << "File cannot be read, opened, or does not exist.\n";
		exit(1);
	}
	string strand;
	while(getline(fin, strand)) 
	{
		cout << DNA_to_mRNA(strand) << endl;		
	}
	fin.close();
}