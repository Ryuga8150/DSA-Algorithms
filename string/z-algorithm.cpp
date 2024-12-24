/*
  TERMS:
  1. Segment Match: those substrings that coincide with a prefix of s
  2. Rightmost Segment Match denoted by [l,r) represents the scanned boundary.

  STEPS:

  1. Initialise the rightmost segments [l,r)
  2. Iterate from i=1.
  3. Use Precomputed Z function values if i < r to get an initial approximation of z[i]
      z[i] = min( r-i, z[i-l] );
      # r-i is taken in case i+z[i-l] values crosses the current boundary.

  4. Apply Brute Force for matches (use z[i] for indexing).
  5. Upate the rightmost segment if i+z[i] > r.
*/
typedef long long int ll;
#include <bits/stdc++.h>
using namespace std;

vector<int> computeZFn(string &s)
{
  int size = s.length();
  vector<int> z(size, 0);

  int l = 0, r = 1;
  for (int i = 1; i < size; ++i)
  {
    if (i < r)
    {
      z[i] = min(r - i, z[i - l]);
    }
    while (i + z[i] < size && s[z[i]] == s[i + z[i]])
    {
      z[i]++;
    }

    if (i + z[i] > r)
    {
      l = i;
      r = i + z[i];
    }
  }

  return z;
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

  vector<int> z = computeZFn(text);

  cout << "Z value of text" << endl;
  display(z);

  string newString = pattern + "$" + text;
  vector<int> Z = computeZFn(newString);
  vector<int> occurences;
  for (int i = patternLen + 1; i < Z.size(); ++i)
  {
    if (Z[i] == patternLen)
      occurences.push_back(i - patternLen - 1);
  }

  cout << "Occurences of pattern in text: " << endl;
  display(occurences);

  return 0;
}