/*
Author: Saurav Hossain
Assignment: Project 2B
Function: Write a program that reads a text file called dna2b.txt that contains one DNA strand per line, converts them to corresponding mRNA strands then outputs to the console the codons.
Date: 03/11/19
Instructor: Panda
File submission name: translatase.cpp
*/
#include <iostream>
#include <fstream>
#include <string> 
#include <cstdlib>
using namespace std;

string dictionary_read(ifstream &dict, string thing) 
{
	string ret;
    string key, value;
    dict.clear(); // reset error state
    dict.seekg(0); // return file pointer to the beginning
    while(dict >> key >> value) 
    {
        if(key == thing)
        {
        	ret = value;
        	break;
        }        
    }
    return ret;
}

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
	ifstream x("codons.tsv");
	if(x.fail()) 
	{
		cerr << "File cannot be read, opened, or does not exist.\n";
		exit(1);
	}
	
	ifstream fin("dna2b.txt");
	if(fin.fail()) 
	{
		cerr << "File cannot be read, opened, or does not exist.\n";
		exit(1);
	}
	string strand;
	while(getline(fin, strand)) 
	{
		//use bool flagger
		bool f = false;
		string newstr = DNA_to_mRNA(strand);
		
		for(int i = 0; i < newstr.length(); i = i + 3)
		{
			string s = newstr.substr(i,3);
			
			if(dictionary_read(x, s) == "Stop") //end sensed before while so stop doesn't print
			{
				f = false;
			}	
			while(f)
			{
				cout << "-" << dictionary_read(x, s);
				break;
			}	
			if(dictionary_read(x, s) == "Met")
			{
				f = true;
				cout << dictionary_read(x, s);
				
			}
		}	
		cout << endl;									
	} 						
	fin.close();	
	x.close();
}	
	
