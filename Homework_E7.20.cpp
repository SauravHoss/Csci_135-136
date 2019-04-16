/*
Author: Saurav Hossain
Date: 04/1/19
Prompt: Define a data-only class Employee with a name and an Employee* pointer to the employee’s manager. For the CEO, that pointer will be a nullptr. Write a program that defines several employees and their managers. For each employee, print the chain of superiors.
*/

#include <iostream>
using namespace std;

//data only so we can use struct
struct Employee
{
  string name;
  Employee * manager;
};

//main method
int main() 
{
  Employee CEO;
  CEO.name = "Kim Bum-joo";
  CEO.manager = nullptr;

  Employee Cheif;
  Cheif.name = "Ahn Chi-soo";
  Cheif.manager = &CEO;

  Employee Deputy;
  Deputy.name = "Lee Jae-han";
  Deputy.manager = &Cheif;

  Employee Detective;
  Detective.name = "Cha Soo-hyun";
  Detective.manager = &Deputy; 

  Employee Rookie;
  Rookie.name = "Park Hae-young";
  Rookie.manager = &Detective; 
}