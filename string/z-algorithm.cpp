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
      r = i + z[i] + 1;
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