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
#include <iostream>
#include <string>
using namespace std;

char shiftChar(char c, int rshift)
{
  char r;
  if(isalpha(c))
  {
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
  }
  else
  {
    r = c;
  }
  return r;
}

string encryptCaesar(string plaintext, int rshift)
{
  string s = "";
  for(int i = 0; i < plaintext.length(); i++)
  {
    char c = plaintext[i];
    s = s + shiftChar(c, rshift);
  }
  return s;
}

int main() 
{
//  cout << shiftChar('v', 7);
  cout << encryptCaesar("Hello, World!", 10);
}

//lab 6c


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


