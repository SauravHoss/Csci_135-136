/*
Author: Saurav Hossain
Assignment: Lab 13C
Function: Write a program defining a function int sumArray(int *arr, int size); which receives an array (as a pointer to its first element) and the size of the array, and should return the sum of its elements.
Date: 05/10/19
Instructor: Panda
File submission name: recursion.cpp
*/

#include <iostream>
using namespace std;

void printRange(int left, int right)
{
  if(left > right)
  {
    return;
  }
  else
  {
    cout << left << endl;
    printRange(left + 1, right);
  }
}

int sumRange(int left, int right)
{
  int sum = 0;
  if(left > right)
    return sum;
  else
  {
   return sum = left + sumRange(left + 1, right);
  }
}

int sumArrayInRange(int *arr, int left, int right)
{
  int sum = 0;
  if(left > right)
    return sum;
  else
  {
    return sum = arr[left] + sumArrayInRange(arr, left + 1, right);
  }
}

int sumArray(int *arr, int size)
{
  int sum = 0;
  if(size <= 0)
    return sum;
  else
  {
    return sumArrayInRange(arr, 0, size-1);
  }
}

int main() 
{
  int size = 10;
  int *arr = new int[size]; // allocate array dynamically
  arr[0] = 12;
  arr[1] = 17;
  arr[2] = -5;
  arr[3] = 3;
  arr[4] = 7;
  arr[5] = -15;
  arr[6] = 27;
  arr[7] = 5;
  arr[8] = 13;
  arr[9] = -21;
  
  int sum1 = sumArray(arr, size); // Add all elements
  cout << "Sum is " << sum1 << endl;  // Sum is 43
  
  int sum2 = sumArray(arr, 5); // Add up first five elements
  cout << "Sum is " << sum2 << endl;  // Sum is 34
  
  delete[] arr;         // deallocate it
}