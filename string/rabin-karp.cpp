typedef long long int ll;

#include <bits/stdc++.h>
using namespace std;

ll m = 1e9 + 9;
ll p = 31;
ll computeHash(string &s)
{
  ll hashValue = 0;
  ll powP = 1;
  for (auto ch : s)
  {
    hashValue = (hashValue + (ch - 'a' + 1) * powP) % m;
    powP = (powP * p) % m;
  }

  return hashValue;
}

vector<int> rabinKarp(string &text, string &pattern)
{
  int textSize = text.size();
  int patternSize = pattern.size();

  vector<ll> powP;

  ll currPower = 1;
  for (int i = 0; i < textSize; ++i)
  {
    powP.push_back(currPower);
    currPower = (currPower * p) % m;
  }

  ll patternHash = computeHash(pattern);

  string str = text.substr(0, patternSize - 1);
  ll currHash = computeHash(str);

  vector<int> ans;
  for (int i = patternSize - 1; i < textSize; ++i)
  {
    currHash = (currHash + ((text[i] - 'a' + 1) * powP[i]) % m) % m;
    if (currHash == patternHash)
    {
      ans.push_back(i + 1 - patternSize);
    }

    currHash = (currHash + m - ((text[i + 1 - patternSize] - 'a' + 1) * powP[i + 1 - patternSize]) % m) % m;
    patternHash = (patternHash * p) % m;
  }

  return ans;
}

int main()
{
  // Sample test cases
  string text1 = "ababcababcabc";
  string pattern1 = "abc";
  vector<int> result1 = rabinKarp(text1, pattern1);

  cout << "Test case 1 results (searching for 'abc' in 'ababcababcabc'):\n";
  if (result1.empty())
  {
    cout << "No match found.\n";
  }
  else
  {
    for (int idx : result1)
    {
      cout << idx << " ";
    }
    cout << "\n";
  }

  string text2 = "thisisaverylongstring";
  string pattern2 = "long";
  vector<int> result2 = rabinKarp(text2, pattern2);

  cout << "Test case 2 results (searching for 'long' in 'thisisaverylongstring'):\n";
  if (result2.empty())
  {
    cout << "No match found.\n";
  }
  else
  {
    for (int idx : result2)
    {
      cout << idx << " ";
    }
    cout << "\n";
  }

  string text3 = "abcdefgh";
  string pattern3 = "xyz";
  vector<int> result3 = rabinKarp(text3, pattern3);

  cout << "Test case 3 results (searching for 'xyz' in 'abcdefgh'):\n";
  if (result3.empty())
  {
    cout << "No match found.\n";
  }
  else
  {
    for (int idx : result3)
    {
      cout << idx << " ";
    }
  }

  return 0;
}