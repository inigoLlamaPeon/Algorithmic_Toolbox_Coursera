#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;

bool higherValue(string str1, string str2);
string largest_number(vector<string> str);

int main()
{
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++)
  {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}

bool higherValue(string str1, string str2)
{
  return stoi(str1 + str2) > stoi(str2 + str1);
}

string largest_number(vector<string> str)
{
  std::stringstream ret;
  while (!str.empty())
  {
    string maxDigit = "0";
    int maxPos = 0;
    size_t i = 0;
    for (i = 0; i < str.size(); i++)
    {
      if (higherValue(str.at(i), maxDigit))
      {
        maxDigit = str.at(i);
        maxPos = i;
      }
    }
    ret << maxDigit;
    str.erase(str.begin() + maxPos);
  }
  string result;
  ret >> result;
  return result;
}