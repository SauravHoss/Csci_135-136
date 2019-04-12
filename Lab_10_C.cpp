/*
Author: Saurav Hossain
Assignment: Lab 10C
Function: Write a function to your program that implements your own printing function printTimeSlot(TimeSlot ts) and write main function that defines at least five time slots.
Date: 04/11/19
Instructor: Panda
File submission name: time.cpp
*/

#include <iostream>
#include <cmath>
using namespace std;

//variable for types of movie
enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

//variable for types of daytime
enum Showtimes {EARLYBIRD, MORNING, AFTERNOON, EVENING, LATENIGHT};

//class time
class Time 
{
  public:
    int h;
    int m;
};

//class movie
class Movie 
{ 
	public: 
    	string title;
    	Genre genre;     // only one genre per movie
    	int duration;    // in minutes
};

//class TimeSlot
class TimeSlot 
{ 
	public: 
    	Movie movie;     // what movie
    	Time startTime;  // when it starts
};

//prints time
void printTime(Time time) 
{
  cout << time.h << ":" << time.m;
}

//prints movie
void printMovie(Movie mv)
{
    string g;
    switch (mv.genre) 
    {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    cout << mv.title << " " << g << " (" << mv.duration << " min)";
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

//prints timeslot
void printTimeSlot(TimeSlot ts)
{
	printMovie(ts.movie);
  cout << " [starts at "; 
	printTime(ts.startTime);
  cout << ", ends by ";

  Time endTime;
  endTime = addMinutes(ts.startTime, ts.movie.duration);

  printTime(endTime); 
  cout << "]";
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
  Movie m;
  m.title = "Sugma";
  m.genre = COMEDY;
  m.duration = 116;

  Time tim = {9, 15};

  TimeSlot t;
  t.movie = m;
  t.startTime = tim;

  printTimeSlot(t);
}