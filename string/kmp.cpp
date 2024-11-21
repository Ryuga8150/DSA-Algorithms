typedef long long int ll;
#include <bits/stdc++.h>
using namespace std;

vector<int> computeLPS(string &s)
{
  int size = s.length();
  int len = 0, i = 1;

  vector<int> lps(size, 0);

  while (i < size)
  {
    if (s[len] == s[i])
    {
      len++;
      lps[i] = len;
      i++;
    }
    else
    {
      if (len != 0)
        len = lps[len - 1];
      else
      {
        lps[i] = 0;
        i++;
      }
    }
  }

  return lps;
}

void display(vector<int> vec)
{
  for (auto val : vec)
  {
    cout << val << " ";
  }
  cout << endl;
}

int main()
{
  string text = "AABAACAADAABAABA";
  int textLen = text.length();

  string pattern = "AAB";
  int patternLen = pattern.length();

  vector<int> lps = computeLPS(text);

  cout << "LPS of text" << endl;
  display(lps);

  string newString = pattern + "$" + text;
  vector<int> LPS = computeLPS(newString);
  vector<int> occurences;
  for (int i = patternLen + 1; i < LPS.size(); ++i)
  {
    if (LPS[i] == patternLen)
      occurences.push_back(i - 2 * patternLen);
  }

  cout << "Occurences of pattern in text: " << endl;
  display(occurences);

  return 0;
}