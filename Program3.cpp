// write a c++ program to find matching pattern and replace with given string
// 9-Dec-2022
#include <iostream>
using namespace std;
class StringOperation
{
public:
  string str;
  string pat;
  string rep;
  string des;
  void getString();
  void checkAndReplace();
};
void StringOperation::getString()
{
  cout << "Enter the String: ";
  getline(cin, str);
  cout << "Enter the pattern: ";
  getline(cin, pat);
  cout << "Enter the replace string: ";
  getline(cin, rep);
  des = "";
}
void StringOperation::checkAndReplace()
{
  bool flag = false;
  int i = 0;
  while (str[i] != '\0')
  {
    int j = 0;
    while ((str[i + j] == pat[j]) && (pat[j] != '\0'))
    {
      j++;
    }
    if (pat[j] == '\0')
    {
      flag = true;
      des += rep;
      // after pattern match i should be at correct location
      i = i + (j - 1);
    }
    else
    {
      des += str[i];
    }
    i++;
  }
  cout << "The result is: ";
  if (flag)
    cout << des << endl;
  else
    cout << "Pattern not found\n";
}
int main()
{
  StringOperation obj;
  obj.getString();
  obj.checkAndReplace();
  return 0;
}
// if this code does not satisfies any condtion then just write their in issue section
