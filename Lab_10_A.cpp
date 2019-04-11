/*
Author: Saurav Hossain
Assignment: Lab 10A
Function: Write a program that implement two functions: int minutesSinceMidnight(Time time); and int minutesUntil(Time earlier, Time later);
Date: 04/11/19
Instructor: Panda
File submission name: time.cpp.
*/

#include <iostream>
using namespace std;

//class time
class Time 
{
  public:
    int h;
    int m;
};

//prints time
void printTime(Time time) 
{
  cout << time.h << ":" << time.m;
}

//minutes since midnight
int minutesSinceMidnight(Time time)
{
  int x = ((time.h * 60) + time.m);
  if(x >= 1440)
    return abs(1440 - x);
  else
    return x;
}

//minutes until time a becomes time b
int minutesUntil(Time earlier, Time later)
{
  return minutesSinceMidnight(later) - minutesSinceMidnight(earlier);
}

//main method
int main() 
{
  int a, b, x , y;
  
  cin >> a >> b;
  cin >> x >> y;

  Time t = {a , b};
  Time u = {x , y};

  cout << minutesSinceMidnight(t) << endl;
  cout << minutesUntil(t, u);
}