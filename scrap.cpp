
#include <cstdlib>
#include <cmath>
#include <iostream>
#include "bot.h"

using namespace std;

const int MAX_ROWS = 40;
const int MAX_COLS = 40;
const int MAX_NUM = 10;

int ROWS;  // global variables
int COLS;
int NUM;

/* onStart: 
An Initialization procedure called at the start of the game.
You can use it to initialize certain global variables, or do 
something else before the actual simulation starts.
Parameters:
    rows: number of rows
    cols: number of columns
    num:  number of dwarfs
    log:  a cout-like log */

void onStart(int rows, int cols, int num, std::ostream &log) 
{
  log << "Start!" << endl; // Print a greeting message

  ROWS = rows; // Save values in global variables
  COLS = cols;
  NUM = num;
}

/*
void lookWorld(int r, int c)
{
	for(int i = 0; i < MAX_ROWS; i++)
    {
    	for(int j = 0; j < MAX_COLS; j++)
    	{
    		if((dwarf.look(i , j) == PINE_TREE) || (dwarf.look(i , j) == APPLE_TREE))
    		{
    			r = i;
    			c = j;
    		}
    	}
    }
}
*/

bool isNextToATree(Dwarf & dwarf, int r, int c)
{
	// Look if there is a tree on the right from the dwarf
	if ((dwarf.look(r, c+1) == PINE_TREE) || (dwarf.look(r, c+1) == APPLE_TREE))
	{
    	// If there is a tree, chop it
    	dwarf.start_chop(EAST);
    	return true;
    }
    // Look if there is a tree on the left from the dwarf
	else if ((dwarf.look(r, c-1) == PINE_TREE) || (dwarf.look(r, c-1) == APPLE_TREE))
	{
    	// If there is a tree, chop it
    	dwarf.start_chop(WEST);
    	return true;
    }
    // Look if there is a tree on the down from the dwarf
	else if ((dwarf.look(r+1, c) == PINE_TREE) || (dwarf.look(r+1, c) == APPLE_TREE))
	{
    	// If there is a tree, chop it
    	dwarf.start_chop(SOUTH);
    	return true;
    }
    // Look if there is a tree on the up from the dwarf
	else if ((dwarf.look(r-1, c) == PINE_TREE) || (dwarf.look(r-1, c) == APPLE_TREE))
	{
    	// If there is a tree, chop it
    	dwarf.start_chop(NORTH);
    	return true;
    }
    else
    	return false;
}


/* onAction: 
A procedure called each time an idle dwarf is choosing 
their next action.
Parameters:
    dwarf:   dwarf choosing an action
    day:     day (1+)
    hours:   number of hours in 24-hour format (0-23)
    minutes: number of minutes (0-59)
    log:     a cout-like log  */

void onAction(Dwarf &dwarf, int day, int hours, int minutes, ostream &log) 
{
  // Get current position of the dwarf
  int r = dwarf.row();
  int c = dwarf.col();
  
  if(isNextToATree(dwarf, r, c))
  {
  	log << "Found a tree -- chop" << endl;
  	return;
  }
  
  else 
  {
  
  	//make non random
    // Otherwise, move to a random location
    int rr = rand() % ROWS;
    int cc = rand() % COLS;
    
      
    log << "Walk to " << rr << " " << cc << endl;
    dwarf.start_walk(rr, cc);
    return;
  }
}

