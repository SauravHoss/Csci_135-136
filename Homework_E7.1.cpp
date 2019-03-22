/*
Author: Saurav Hossain
Date: 03/20/19
Prompt: Write a function void sort2(double* p, double* q) that receives two pointers and sorts the values to which they point,  so that if you call sort2(&x, &y) x become less then or equal to y after the call.
*/

#include <iostream>
using namespace std;

void sort2(double * x, double * y)
{
  if(*x > * y)
  {
    double temp;
    temp = * x;
    * x = * y;
    * y = temp;
  }
}

int main(void)
{
  double x = 3.3, y = 9.5;
  sort2(&x, &y);
  cout << x << " " << y << endl;  
}