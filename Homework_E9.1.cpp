/*
Author: Saurav Hossain
Date: 04/16/19
Prompt: We want to add a button to the tally counter example that allows an operator to undo an accidental button click. Provide a member function void undo()that simulates such a button. As an added precaution, make sure that the operator cannot click the undo button more often than the count button.
*/

//class structure and main method were provided
#include <iostream>
using namespace std;

class Counter
{
  public:
    void undo();
    void reset();
    void count();
    int get_value() const;
  private:
    int value;
};

void Counter::count()
{
  value++;
}
void Counter::reset()
{
  value = 0;
}
int Counter::get_value() const
{
  return value;
}

void Counter::undo()
{
  if(value > 0)
  {
    value--;
  }
}

int main() 
//define and use 2 Counter objects to test class
{
  Counter tally;
  tally.reset();
  tally.count();
  tally.count();
  tally.undo();
  int result = tally.get_value();
  cout << "Value of tally: " << result << endl;

  tally.count();
  tally.count();
  tally.undo();
  result = tally.get_value();
  cout << "Value of tally: " << result << endl;

  Counter concert_counter;
  concert_counter.reset();
  concert_counter.count();
  concert_counter.count();
  concert_counter.count();
  concert_counter.undo();
  result = concert_counter.get_value();
  cout << "Value of concert_counter: " << result << endl;
  return 0;
}