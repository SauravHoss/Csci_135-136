/*
Author: Saurav Hossain
Assignment: Project 2D
Function: Write a program that compares the results of Task B with the mutated strands. To do this, you will need to parse the strands one nucleotide at a time as the “Start” codon is not a guaranteed multiple of 3 from the begining. Your output should be the original protein on the even lines, and the mutated protein on the odd lines.
Date: 04/03/19
Instructor: Panda
File submission name: frameshift.cpp
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

//converts codons to amino acids
string c_to_Acid(string s)
{
	ifstream x("codons.tsv");
	if(x.fail()) 
	{
		cerr << "File cannot be read, opened, or does not exist.\n";
		exit(1);
	}

    string c, a = "";
    while(x >> c >> a)
    {
    	if(s == c)
    	{
    		return a;
    	}
    }
    return "Fucked";
}

//makes mRNA to codon
string mRNA_to_Acid(string s)
{
	string acid = "";
    bool flag = false;
    string now = "";
 
    for(int i = 0; i < s.length(); i+=3)
    {		
    	now = s.substr(i,3);

    	if(now == "AUG")
    	{
    		flag = true;
		}
    	if(now == "UAG" || now == "UGA" || now == "UAA")
    	{
    		acid = acid.substr(0, acid.length()-1); 
    		return acid;
    	}    	
    	if(flag)
    	{
    		if(c_to_Acid(now) != "Fucked") 
    		{
    			acid += c_to_Acid(now);
    			acid += "-";	
    		}
    	}
    }
    return acid.substr(0, acid.length()-1);
}

//cuts out the useless front 
string truncate(string s)
{
	for(int i = 0; i < s.length(); i++)
	{
		if(s.substr(i,3) == "AUG")
		{
			return s.substr(i, s.length()-1);
		}
	}
	return "Fucked";
}

//main method 
int main()
{
	ifstream in("frameshift_mutations.txt");
	if (in.fail())
	{
        cerr << "File cannot be read, opened, or does not exist.\n";
        exit(1);
    }

	string dna1, dna2;
	while(getline(in, dna1)) 
	{
		getline(in, dna2);
		cout << mRNA_to_Acid(DNA_to_mRNA(dna1)) << endl; 
		cout << mRNA_to_Acid(truncate(DNA_to_mRNA(dna2))) << endl;
	}
}