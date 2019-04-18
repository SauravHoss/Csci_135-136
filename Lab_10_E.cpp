/*
Author: Saurav Hossain
Assignment: Lab 10E
Function: Write a function that should return true if the two time slots overlap, otherwise return false. (Take into account the starting times of the time slots and the duration of the scheduled movies.)
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

//returns timeslot of new movie
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie)
{
  TimeSlot nextts;
  nextts.movie = nextMovie;
  nextts.startTime = addMinutes(ts.startTime, ts.movie.duration);
  return nextts;
}

//shows if times overlap
bool timeOverlap(TimeSlot ts1, TimeSlot ts2)
{
	int ts1_start = minutesSinceMidnight(ts1.startTime);
	int ts1_stop = minutesSinceMidnight(addMinutes(ts1.startTime, ts1.movie.duration));
	int ts2_start = minutesSinceMidnight(ts2.startTime);
	int ts2_stop = minutesSinceMidnight(addMinutes(ts2.startTime, ts2.movie.duration));

    return ((ts2_start >= ts1_start && ts2_start <= ts1_stop) || (ts2_stop >= ts1_start && ts2_stop <= ts1_stop)) || ( (ts1_start >= ts2_start && ts1_start <= ts2_stop) || (ts1_stop >= ts2_start && ts1_stop <= ts2_stop));
}

//main method
int main() 
{
/*
  Movie m;
  m.title = "Sugma";
  m.genre = COMEDY;
  m.duration = 65;

  Time time1 = {9, 0};
  Time time2 = {10, 5};

  TimeSlot t1;
  t1.movie = m;
  t1.startTime = time1;

  TimeSlot t2;
  t2.movie = m;
  t2.startTime = time2;

  cout << timeOverlap(t1, t2);
*/
  cout << timeOverlap({{"The Wolf of Wall Street", COMEDY, 180}, {10, 30}}, {{"5 Centimeters Per Second", DRAMA, 63}, {8, 30}});
}