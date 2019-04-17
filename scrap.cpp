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
};

// 0 for down, 1 for up
int Circuit:: get_first_switch_state()
{
  return first_switch;
} 

int Circuit:: get_second_switch_state()
{
  return second_switch;
}

// 0 for off, 1 for on
int Circuit:: get_lamp_state()
{
  return lamp;
} 

void Circuit:: toggle_first_switch()
{
  if(first_switch == 1)
    first_switch = 0;
  else 
    first_switch = 1;
}

void Circuit:: toggle_second_switch()
{
  if(second_switch == 1)
    second_switch = 0;
  else
    second_switch = 1;
}

int main() 
{
  
}
