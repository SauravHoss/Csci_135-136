#include <cstdlib>
#include <cmath>
#include <iostream>
#include "bot.h"
#include <cmath>

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

//checks if tree next to given location
bool isNextToATree(Dwarf & dwarf, int r, int c)
{
	if ((dwarf.look(r - 1, c) == PINE_TREE || dwarf.look(r + 1, c) == PINE_TREE || dwarf.look(r, c - 1) == PINE_TREE || dwarf.look(r, c + 1) == PINE_TREE || dwarf.look(r - 1, c) == APPLE_TREE || dwarf.look(r + 1, c) == APPLE_TREE || dwarf.look(r, c - 1) == APPLE_TREE || dwarf.look(r, c + 1) == APPLE_TREE) && dwarf.look(r, c) == EMPTY)
  {
		return true;
  }
  else
  {
		return false;
  }
}

int distanceOfTree(int x, int y, int x2, int y2)
{
	return sqrt(((x - x2)*(x - x2)) + ((y - y2)*(y - y2)));
}

//row by col search, find closest row of tree then col

int rowCheck(Dwarf &dwarf)
{
	// get current and set to find closest working rows of tree
	int r = dwarf.row();
	int c = dwarf.col();


	int max = INT8_MAX;
	int row_trees = 0;
	
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (isNextToATree(dwarf, i, j))
			{
				if (distanceOfTree(r, c, i, j) < max)
				{
					max = distanceOfTree(r, c, i, j);
					row_trees = i;
				}
			}
		}
	}
	return row_trees;
}

int columnCheck(Dwarf &dwarf)
{	
	//find closest col of tree after row
	int r = dwarf.row();
	int r2 = rowCheck(dwarf);
	int c = dwarf.col();

	int max = INT8_MAX;
	int col_trees = 0;
	
	for (int i = 0; i < COLS; i++)
	{
		if (isNextToATree(dwarf, r2, i))
		{
			if (distanceOfTree(r, c, r2, i) < max)
			{
				max = distanceOfTree(r, c, r2, i);
				col_trees = i;
			}
		}
	}
	return col_trees;
}

void collect(Dwarf &dwarf, ostream &log)
{
  // Get current position of the dwarf
  int r = dwarf.row();
  int c = dwarf.col();

  // Look if there is a tree on the right from the dwarf
  if (dwarf.look(r, c+1) == PINE_TREE || dwarf.look(r, c + 1) == APPLE_TREE) 
  {
	// If there is a pine tree, chop it
	log << "Found a tree -- chop" << endl;
	dwarf.start_chop(EAST);
	return;
  }
  // Look if there is a tree on the left from the dwarf
  else if (dwarf.look(r, c - 1) == PINE_TREE || dwarf.look(r, c - 1) == APPLE_TREE) 
  {
	// If there is a pine tree, chop it
	log << "Found a tree -- chop" << endl;
	dwarf.start_chop(WEST);
	return;
  }
  // Look if there is a tree on the up from the dwarf
  else if (dwarf.look(r + 1, c) == PINE_TREE || dwarf.look(r + 1, c) == APPLE_TREE) 
  {
	// If there is a pine tree, chop it
	log << "Found a tree -- chop" << endl;
	dwarf.start_chop(SOUTH);
	return;
  }
  // Look if there is a tree on the down from the dwarf
  else if (dwarf.look(r - 1,c) == PINE_TREE || dwarf.look(r - 1, c) == APPLE_TREE) 
  {
	// If there is a pine tree, chop it
	log << "Found a tree -- chop" << endl;
	dwarf.start_chop(NORTH);
	return;
  }
  else 
  {
    int r_next = rowCheck(dwarf);
    int	c_next = columnCheck(dwarf);
    log << "Walk to " << r_next << " " << c_next << endl;
    dwarf.start_walk(r_next, c_next);
    return;
  }	
}

bool areTrees(Dwarf &dwarf, ostream &log)
{
	for(int i = 0; i < ROWS; i++)
	{
		for(int j = 0; j < COLS; j++)
		{
			if(dwarf.look(i, j) == PINE_TREE || dwarf.look(i, j) == APPLE_TREE)
			{
				return false;
			}
		}
	}
	return true;
}

bool toFirst(Dwarf &dwarf)
{
  	if((dwarf.row()==1 && dwarf.col()==dwarf.name()) || dwarf.look(0, dwarf.name()) == FENCE )
  	{
  		return true;
  	}
  	else
  	{
  		return false;
  	}
}

void bobTheBuilder(Dwarf &dwarf, ostream &log)
{
	int r = dwarf.row();
	dwarf.start_walk(r + 1, dwarf.name());
	dwarf.start_build(NORTH);
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

  bool notrees = areTrees(dwarf, log);
  int r = dwarf.row();
  int c = dwarf.col();

  if(!notrees)
  {
  	collect(dwarf, log);
  }
  else
  {
  	if(!toFirst(dwarf))
  	{
  		int row = 1;
  		dwarf.start_walk(row, dwarf.name());
  		return;
  	}
  	else
  	{
  		if(dwarf.look(dwarf.row() - 1, dwarf.name()) == EMPTY)
  		{
  			dwarf.start_build(NORTH);
  			return;
  		}
  		else if(dwarf.look(dwarf.row() - 1, dwarf.name()) == FENCE)
  		{
  			dwarf.start_walk(dwarf.row() + 1, dwarf.name());
  			return;
  		}
  	}  	
  }
}
