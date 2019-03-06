// lab 6a 
#include <iostream>
#include <string>
using namespace std;

int main() 
{
  string s;
  cin >> s;

  for(int i = 0; i < s.length(); i++)
  {
    cout << s[i] << " " << (int)s[i] << endl;
  }

}

// lab 6b


//loops upper and lower case
char shiftChar(char c, int rshift)
{
  char r;
  if((int)c <= 122 && (int)c >= 97 )
  {
    if(((int)c + rshift) > 122)
    {
      int x = ((int)c + rshift) - 122;
      r = 96 + x;
    } 
    else
      r = (int)c + rshift;
  }
  else if((int)c <= 90 && (int)c >= 65 )
  {
    if(((int)c + rshift) > 90)
    {
      int x = ((int)c + rshift) - 90;
      r = 64 + x;
    } 
    else
      r = (int)c + rshift;
  }
  return r;
}


