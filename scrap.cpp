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
Lab_2C
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
Lab_2D
#include <iostream>
using namespace std;

int main ()
{
  int fib[60] = {0,1};  

  for(int i = 2; i < 60 ; i++)
  {
    fib[i] = fib[i-2] + fib[i-1];
  }

  for(int i = 0; i < 60; i++)
  {
    cout << fib[i] << "\n";
  }
}
