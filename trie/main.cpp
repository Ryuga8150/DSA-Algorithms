#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  Node *children[26];
  bool isEnd = false;
};

class Trie
{
private:
  Node *root;

public:
  Trie()
  {
    root = new Node();
  }

  void insertWord(string &word)
  {
    Node *currNode = root;

    for (auto ch : word)
    {
      if (!currNode->children[ch - 'a'])
      {
        currNode->children[ch - 'a'] = new Node();
      }
      currNode = currNode->children[ch - 'a'];
    }
    currNode->isEnd = true;
  }

  bool searchWord(string &word)
  {
    Node *currNode = root;

    for (auto ch : word)
    {
      if (!currNode->children[ch - 'a'])
      {
        return false;
      }
      currNode = currNode->children[ch - 'a'];
    }

    return currNode->isEnd;
  }

  bool startsWith(string &word)
  {
    Node *currNode = root;

    for (auto ch : word)
    {
      if (!currNode->children[ch - 'a'])
      {
        return false;
      }
      currNode = currNode->children[ch - 'a'];
    }

    return true;
  }
};

int main()
{
  Trie trie;

  // Test Case 1: Insert and Search for Existing Word
  string word1 = "apple";
  trie.insertWord(word1);
  cout << "Search for \"" << word1 << "\": " << (trie.searchWord(word1) ? "Found" : "Not Found") << endl;

  // Test Case 2: Search for Non-existent Word
  string word2 = "app";
  cout << "Search for \"" << word2 << "\": " << (trie.searchWord(word2) ? "Found" : "Not Found") << endl;

  // Test Case 3: Insert and Search for Prefix
  string prefix = "app";
  cout << "Starts with \"" << prefix << "\": " << (trie.startsWith(prefix) ? "Yes" : "No") << endl;

  return 0;
}
