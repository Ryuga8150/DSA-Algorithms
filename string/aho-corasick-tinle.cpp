#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
  TrieNode *sfx, *dict, *children[26];
  int id = -1;
};

static TrieNode nodes[(int)5e4 + 1];

class Trie
{
public:
  TrieNode *root;
  int count = 0;
  TrieNode *newTrieNode()
  {
    nodes[count] = TrieNode();
    return &nodes[count++];
  }

  Trie(vector<string> &words, vector<int> &costs, string target)
  {
    root = newTrieNode();
    root->sfx = root->dict = root;
  }

  void insert(const string &s)
  {
    TrieNode *curr = root;
    for (auto &ch : s)
    {
      if (!curr->children[ch - 'a'])
        curr->children[ch - 'a'] = newTrieNode();
      curr = curr->children[ch - 'a'];
    }
  }

  void aho_corasick()
  {
    queue<TrieNode *> q;
    q.push(root);
    while (!q.empty())
    {
      TrieNode *par = q.front();
      q.pop();
      for (int i = 0; i < 26; i++)
      {
        TrieNode *child = par->children[i];
        if (!child)
          continue;
        TrieNode *suff = par->sfx;
        while (suff != root && !suff->children[i])
          suff = suff->sfx;
        if (par != root && suff->children[i])
          child->sfx = suff->children[i];
        else
          child->sfx = root;

        child->dict = child->sfx->id == -1 ? child->sfx->dict : child->sfx;
        q.push(child);
      }
    }
  }

  void queries(TrieNode *&prev, int i, char ch)
  {
    while (prev != root && !prev->children[ch - 'a'])
      prev = prev->sfx;
    if (prev->children[ch - 'a'])
    {
      prev = prev->children[ch - 'a'];
      TrieNode *curr = prev->id == -1 ? prev->dict : prev;
      while (curr->id != -1)
      {
        int j = curr->id;
        curr = curr->dict;
      }
    }
  }
};