/*
Author: Saurav Hossain
Date: 04/16/19
Prompt: Simulate a circuit for controlling a hallway light that has switches at both ends of the hallway. Each switch can be up or down, and the light can be on or off. Toggling either switch turns the lamp on or off. Provide member functions
  int get_first_switch_state() // 0 for down, 1 for up
  int get_second_switch_state()
  int get_lamp_state() // 0 for off, 1 for on
  void toggle_first_switch()
  void toggle_second_switch()
*/

#include <iostream>
using namespace std;

class Circuit
{
  public:
    int first_switch;
    int second_switch;
    int lamp;
    int get_first_switch_state(); // 0 for down, 1 for up
    int get_second_switch_state();
    int get_lamp_state(); // 0 for off, 1 for on
    void toggle_first_switch();
    void toggle_second_switch();
  Circuit()
  {
    first_switch = 0;
    second_switch = 0;
    lamp = 0;
  }
};

//getter for first switch
int Circuit::get_first_switch_state()
{
  return first_switch;
}

//getter for second switch
int Circuit::get_second_switch_state()
{
  return second_switch;
}

//getter for lamp
int Circuit::get_lamp_state()
{
  return lamp;
}

//toggles switch and turns on lamp
void Circuit::toggle_first_switch()
{
  if(first_switch == 0 && get_lamp_state() == 0)
  {
    first_switch = 1;
    lamp = 1;
  }
  else if(first_switch == 1 && get_lamp_state() == 0)
  {
    first_switch = 0;
    lamp = 1;
  }
  else if(first_switch == 0 && get_lamp_state() == 1)
  {
    first_switch = 1;
    lamp = 0;
  }
  else if(first_switch == 1 && get_lamp_state() == 1)
  {
    first_switch = 0;
    lamp = 0;
  }
}

//toggles switch and turns on lamp
void Circuit::toggle_second_switch()
{
  if(second_switch == 0 && get_lamp_state() == 0)
  {
    second_switch = 1;
    lamp = 1;
  }
  else if(second_switch == 1 && get_lamp_state() == 0)
  {
    second_switch = 0;
    lamp = 1;
  }
  else if(second_switch == 0 && get_lamp_state() == 1)
  {
    second_switch = 1;
    lamp = 0;
  }
  else if(second_switch == 1 && get_lamp_state() == 1)
  {
    second_switch = 0;
    lamp = 0;
  }
}

int main()
{
  Circuit c;

  c.toggle_first_switch();

  cout << c.get_lamp_state();

  c.toggle_first_switch();

  cout << c.get_lamp_state();

  c.toggle_second_switch();

  cout << c.get_lamp_state();
}