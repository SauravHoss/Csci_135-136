/*
Author: Saurav Hossain
Assignment: Lab 10B
Function: Write a function to your program Time addMinutes(Time time0, int min);The function should create and return a new moment of time that is min minutes after time0.
Date: 04/11/19
Instructor: Panda
File submission name: time.cpp
*/

#include <iostream>
#include <cmath>
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

//converts minutes to time
Time minToTime(int min)
{
  int mins = min % 60;
  int hours =  min / 60;

  Time t = {hours, mins};
  return t;
}

//adds minutes to given time and returns new time
Time addMinutes(Time time0, int min)
{
  return minToTime(((time0.h * 60) + time0.m) + min);
}

//main method
int main() 
{
  int a, b, x;
 
  cin >> a >> b;
  cin >> x;

  Time t = {a , b};
  
  printTime(addMinutes(t, x));
}