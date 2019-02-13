/*
Author: Saurav Hossain
Assignment: Project 1B
Function: Write a program that reads from the cin a sequence of one or more non-negative integers written to be added or subtracted. Space characters can be anywhere in the input. After the input ends (end-of-file is reached), the program should compute and print the result of the input summation.
Date: 02/03/19
Instructor: Panda
File submission name: calc.cpp
*/
#include <iostream>
using namespace std;
int main ()
{
  int x,v;
  cin >> x;
  char o;
  while (cin >> o >> v)
  {    
    while( o != ';')
    {
    	if(o == '+')
    	{ 
      		x += v;	
    	}
    	else if( o == '-')
    	{
      		x -= v;
    	}
    }
	cout << x << endl;
	x = 0;
  }
}


#include <iostream>
using namespace std;
int main ()
{
  int x,v;
  cin >> x;
  char o;

  while (cin >> o)
  { 
  	while(cin >> v)
  	{   
    	if(o == '+')
   	 	{ 
    	  x += v;	
    	}
    	else if (o == '-')
    	{
      		x -= v;
    	}
    	cout << x;
  	}
  }
}
