#include <cstdlib>
#include <cmath>
#include <tuple>
#include <iostream>
#include "bot.h"

using namespace std;

const int MAX_ROWS = 40;
const int MAX_COLS = 40;
const int MAX_NUM = 10;

int ROWS;  // global variables
int COLS;
int NUM;
//int MAP[MAX_ROWS][MAX_COLS];

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
//get the entire map
void lookWorld(Dwarf & dwarf, int r, int c)
{
	for(int i = 0; i < MAX_ROWS; i++)
    {
    	for(int j = 0; j < MAX_COLS; j++)
    	{
    		if((dwarf.look(i , j) == PINE_TREE) || (dwarf.look(i , j) == APPLE_TREE))
    		{
    			MAP[i][j] = 1;
    		}
    		else 
    			MAP[i][j] = 0;
    	}
    }
}
*/

void findNextTree(Dwarf & dwarf, int r, int c, ostream &log, int range)
{
	if(range + r >= MAX_ROWS || range + c >= MAX_COLS || r - range <= 0 || c - range <=0)
	{
		range = 2;
		dwarf.start_walk((rand() % ROWS), (rand() % COLS));	
	}

	if((dwarf.look(r, c+range) == PINE_TREE) || (dwarf.look(r, c+range) == APPLE_TREE))
	{
		if(dwarf.look(r, c+(range -1)) == EMPTY)
        {    
  	      	log << "LOOKING" << "RANGE: " << range << endl;
            dwarf.start_walk(r, c+(range - 1));
        }
        else
   		{
   			log << "SOMETHING BAD IS HAPPENING!" << endl;
        	findNextTree(dwarf, r, c, log, range + 1);    
    	} 
	}
	else if((dwarf.look(r, c-range) == PINE_TREE) || (dwarf.look(r, c-range) == APPLE_TREE))
	{
	
		if(dwarf.look(r, c-(range -1)) == EMPTY)
        {    
			log << "LOOKING" << "RANGE: " << range << endl;
            dwarf.start_walk(r, c-(range - 1));
        }
        else
   		{
   			log << "SOMETHING BAD IS HAPPENING!" << endl;
        	findNextTree(dwarf, r, c, log, range + 1);    
    	} 	
	}
	else if((dwarf.look(r+range, c) == PINE_TREE) || (dwarf.look(r+range, c) == APPLE_TREE))
	{
		if(dwarf.look(r+(range -1), c) == EMPTY)
        {    
			log << "LOOKING" << "RANGE: " << range << endl;
			dwarf.start_walk(r+(range - 1), c);		
        }
        else
   		{
   			log << "SOMETHING BAD IS HAPPENING!" << endl;
        	findNextTree(dwarf, r, c, log, range + 1);    
    	}
	}
	else if((dwarf.look(r-range, c) == PINE_TREE) || (dwarf.look(r-range, c) == APPLE_TREE))
	{
	
		if(dwarf.look(r-(range -1), c) == EMPTY)
        {    
			log << "LOOKING" << "RANGE: " << range << endl;
			dwarf.start_walk(r-(range - 1), c);
        }
        else
   		{
   			log << "SOMETHING BAD IS HAPPENING!" << endl;
        	findNextTree(dwarf, r, c, log, range + 1);    
    	}	
	}
	else
	{
		findNextTree(dwarf, r, c, log, range + 1);	
	}	
	
}

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
  findNextTree(dwarf, r, c, log, 2);
  log << "Walk to " << r << " " << c << endl;

  /*
  	//make non random
    // Otherwise, move to a random location
    int rr = rand() % ROWS;
    int cc = rand() % COLS;
    
      
    dwarf.start_walk(rr, cc);
    */
    return;
  }
}
 
