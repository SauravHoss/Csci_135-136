/*
Author: Saurav Hossain
Date: 04/04/19
Prompt: Define a trivial class Triangle that contains three Point members. Write a function that computes the perimeter of a Triangle. Write a program that reads the coordinates of the points, calls your function, and displays the result.
*/

#include <iostream>
#include <cmath>
using namespace std;

//a struct to group ints together as a point
struct Point
{
  int x, y;
};

//class triangle with the class variables of points a, b, c and directly pass them in as parameters for the function to calculate the perimeter 
class Triangle
{
  public:
    Point a, b, c;
    //can set a.x of Point a to an int but no real need
    int perimeterCalc(Point a, Point b, Point c)
    {
      //use distance formula on each point for a side
      int sidea = sqrt(((b.x - a.x) * (b.x - a.x)) + ((b.y - a.y) * (b.y - a.y)));
      int sideb = sqrt(((c.x - b.x) * (c.x - b.x)) + ((c.y - b.y) * (c.y - b.y)));
      int sidec = sqrt(((c.x - a.x) * (c.x - a.x)) + ((c.y - a.y) * (c.y - a.y)));
      return sidea + sideb + sidec;
    }
};

int main() 
{
  //Given Points
  Point dog = {0, 0};
  Point cat = {4, 0};
  Point mouse = {4, 3};

  //make triangle object an call on perimeterCalc to calculate it
  Triangle shape1;
  cout << "The perimeter is : " << shape1.perimeterCalc(dog, cat, mouse);
}