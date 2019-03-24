/*
Author: Saurav Hossain
Assignment: Project 2C
Function: Write a program called that calculates the Hamming distance between two strings. Given two strings of equal length, the Hamming distance is the number of positions at which the two strings differ. Output to the console the Hamming distance followed by “yes” or “no” whether the substitution caused a change in structure. 
Date: 03/24/19
Instructor: Panda
File submission name: hamming.cpp
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

//returns # of differences  
int hamming(string x, string y)
{
	int c = 0;
	for(int i = 0; i < x.length(); i++)
	{
		if(x[i] != y[i])
		{
			c++;
		}
	} 
	return c;
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
	
	ifstream fin("mutations.txt");
	if(fin.fail()) 
	{
		cerr << "File cannot be read, opened, or does not exist.\n";
		exit(1);
	}
	string strand;
	string dna1, dna2;
	
	while(getline(fin, strand)) 
	{
		dna1 = strand;
		getline(fin, dna2);
		
		//use bool flagger
		bool f = false;
		string newstr = DNA_to_mRNA(dna1);
		string newstr2 = DNA_to_mRNA(dna2);
		string yn = " no";
		string c1, c2;
		
		//for one string 
		for(int i = 0; i < newstr.length(); i = i + 3)
		{
			string s = newstr.substr(i,3);
			
			if(dictionary_read(x, s) == "Stop") //end sensed before while so stop doesn't print
			{
				f = false;
			}	
			while(f)
			{
				c1 = c1 + dictionary_read(x, s);
				break;
			}	
			if(dictionary_read(x, s) == "Met")
			{
				f = true;
			}
		}	
		
		//for the other
		for(int i = 0; i < newstr2.length(); i = i + 3)
		{
			string s2 = newstr2.substr(i,3);
			
			if(dictionary_read(x, s2) == "Stop") //end sensed before while so stop doesn't print
			{
				f = false;
			}	
			while(f)
			{
				c2 = c2 + dictionary_read(x, s2); 
				break;
			}	
			if(dictionary_read(x, s2) == "Met")
			{
				f = true;
			}
		}	
		
		//check if same
		if(c1 != c2)
		{
			yn = " yes";
		}
		cout << hamming(dna1, dna2) << yn << endl;
									
	} 	
								
	fin.close();	
	x.close();
}	