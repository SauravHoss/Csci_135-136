/*
Author: Saurav Hossain
Assignment: Lab 5A, 5B, 5C, 5D, 5E, 5F, 5G
Function: 
A. Write a program that defines a function. If n is divisible by d, the function should return true, otherwise return false.
B. Add a function that should return true if n is a prime, otherwise return false.
C. Add a function that returns the smallest prime greater than n.
D. Add a function that returns the number of prime numbers in the interval a ≤ x ≤ b.
E. Add a function that determines whether or not its argument is a twin prime. 
F. Add a function that returns the smallest twin prime greater than n.
G. Add a function that returns the largest twin prime in the range a ≤ N ≤ b. If there is no twin primes in range, then return -1.
Date: 02/27/19
Instructor: Panda
File submission name: numbers.cpp
SEE NEW COMMENT
more comment	
MORE COMMENTS ARE YOU HAPPY
GRADING SCRIPT
*/
#include <iostream>
using namespace std;

//returns if x is divisible by y or not
bool isDivisibleBy(int x, int y)
{
  if(y != 0)
  {
    if(x % y == 0)
      return true;
    else 
      return false;
  }
  else 
   return false;
}

//returns if a number is prime or not
bool isPrime(int x)
{
  if(x > 1)
  {
	  for(int i = 2; i < x-1; i++)
	  {
	     if(x % i ==0)
	     {
	     	return false;
		break;
	     }
	  }
	  return true;
  }
  else 
    return false;
}

//finds next prime number given a number
int nextPrime(int x)
{
  x = x + 1;
  while(!isPrime(x))
  {
    x++;
  }
  return x;
}

//counts the amount of prime numbers between x and y
int countPrimes(int x, int y)
{
  int c = 0;
  for(int i = x; i < y + 1; i++)
  {
    if(isPrime(i))
    {
      c++;
    }
  }
  return c;
}

//returns if a number is twin prime or not
bool isTwinPrime(int x)
{
  if(isPrime(x))
  {
    if((isPrime(x - 2)) || isPrime(x + 2))
      return true;
    else 
      return false; 
  }   
  else return false;
}

//returns the next twin prime number given a number
int nextTwinPrime(int x)
{
  int y = 0;
  while(y == 0)
  {
    x++;
    if(isTwinPrime(x))
    {
      y = x;
    }
  }
  return y;
}

//finds the largest twin prime given x and y
int largestTwinPrime(int x, int y)
{
  int f = 0;
  for(int i = y; i > x; i--)
  {
    if(isTwinPrime(i))
    {
      f = i;
      break;
    }
  }
  if(f > 0)
    return f;
  else
    return -1;
}

//main method 
int main() 
{ 
// Comment off the multilines to test them
  /*
  Function A
  int x, y;
  cin >> x;
  cin >> y;
  if(isDivisibleBy(x, y))
    cout << "True";
  else
    cout << "False";
  */
  
  /*
  Function B
  int x;
  cin >> x;
  if(isPrime(x))
    cout << "True";
  else
    cout << "False"; 
  */
  
  /*
  Function C
  int x;
  cin >> x;
  int y = nextPrime(x);
  cout << y;
  */
  
  /*
  Function D  
  int x, y;
  cin >> x;
  cin >> y;
  cout << (countPrimes(x, y));
  */
  
  /*
  Function E
  int x;
  cin >> x;
  cout << (isTwinPrime(x));
  */
  
  /*
  Function F
  int x;
  cin >> x;
  cout << (nextTwinPrime(x));
  */

  /*
  Function G
  int x, y;
  cin >> x;
  cin >> y;
  cout << (largestTwinPrime(x, y));
  */ 
}