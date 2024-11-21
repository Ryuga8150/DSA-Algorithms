typedef long long int ll;
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  Node *children[26];
  Node *suffixLink;
  Node *outputLink;
  bool patternInd;

  Node()
  {
    suffixLink = nullptr;
    outputLink = nullptr;
    patternInd = -1
  }
};

class Trie
{
  Node *root;

public:
  Trie()
  {
    root = new Node();
    root->suffixLink = root;
  }
  void insertWord(string &s, int index)
  {
    Node *currNode = root;
    for (auto ch : s)
    {
      if (!currNode->children[ch - 'a'])
        currNode->children[ch - 'a'] = new Node();

      currNode = currNode->children[ch - 'a']
    }
    currNode->patternInd = index;
  }

  void buildTrie(vector<string> &pattern)
  {
    int patternSize = pattern.size();
    for (int i = 0; i < patternSize; ++i)
    {
      insertWord(pattern[i], i);
    }
  }

  void buildLinks()
  {
    queue<Node *> q;

    q.push(root);

    while (!q.empty())
    {
      Node *currNode = q.front();
      q.pop();

      for (int i = 0; i < 26; ++i)
      {
        Node *currNodeChild = currNode->children[i];

        if (!currNodeChild)
          continue;

        Node *suffixLinkNode = currNode->suffixLink;

        while (suffixLinkNode != root && !suffixLinkNode->children[i])
          suffixLinkNode = suffixLinkNode->suffixLink;

        if (!suffixLinkNode->children[i])
          currNodeChild->suffixLink = root;
        else
          currNodeChild->suffixLink = suffixLinkNode->children[i];

        q.push(currNodeChild);
      }

      if (currNode->suffixLink->patternInd >= 0)
        currNode->outputLink = currNode->suffixLink;
      else
        currNode->outputLink = currNode->suffixLink->outputLink;
    }
  }
};

int main()
{

  return 0;
}