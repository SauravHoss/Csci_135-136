Lab_2A
#include <iostream>
using namespace std;

int main() 
{
  int x;
  cout << "Enter a number between 0 and 100\n";
  cin >> x;

  while(x <= 0 || x >= 100)
  {
    cout << "Enter a number between 0 and 100\n";
    cin >> x;
  }
    cout << "The number squared is " << (x*x); 
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Lab_2B
#include <iostream>
using namespace std;

int main() 
{
  int x,y;
  cin >> x;
  cin >> y;

  for(int i = x; i < y; i++)
  {
    cout << i << " ";
  }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

int main ()
{
  int myData[10] = {1};
  for (int n = 0; n < 10; n++)
    {
      myData[n] = 1;
    }

  int x,y;
  do
  {
    //prints array
    for (int n = 0; n < 10; n++)
    {
      cout << myData[n];
    }
    cout << "\n";
    cin >> x;
    cin >> y;

    myData[x] = y;

  }
  while(x >= 0 && x < 10);
  cout << "Exit.";
  
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
