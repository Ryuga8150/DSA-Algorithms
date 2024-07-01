#include <bits/stdc++.h>

using namespace std;

// n+1 so that it works for both 0 and 1 based
// u is king in case of equality

class DisjointSet
{
  vector<int> parent, rank, size;

public:
  DisjointSet(int n)
  {
    parent.resize(n + 1);
    rank.resize(n + 1, 0);
    size.resize(n + 1, 1);
    for (int i = 0; i <= n; ++i)
    {
      parent[i] = i;
    }
  }

  int findUPar(int node)
  {
    if (parent[node] == node)
      return node;

    return parent[node] = findUPar(parent[node]);
  }

  void unionByRank(int u, int v)
  {
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v);

    if (ulp_u == ulp_v)
      return;

    if (rank[u] < rank[v])
    {
      parent[ulp_u] = ulp_v;
    }
    else if (rank[v] < rank[u])
    {
      parent[ulp_v] = ulp_u;
    }
    else
    {
      parent[ulp_v] = ulp_u;
      rank[ulp_u]++;
    }
  }

  void unionBySize(int u, int v)
  {
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v);

    if (ulp_u == ulp_v)
      return;

    if (size[u] < size[v])
    {
      parent[ulp_u] = ulp_v;
      size[ulp_v] += size[ulp_u];
    }
    else
    {
      parent[ulp_v] = ulp_u;
      size[ulp_u] += size[ulp_v];
    }
  }
};

int main()
{
  // Example usage of the DisjointSet class
  int n = 10; // Example: creating a DisjointSet for elements 0 to 9

  DisjointSet ds(n);

  // Example of union by rank
  // ds.unionByRank(1, 2);
  // ds.unionByRank(2, 3);
  // ds.unionByRank(4, 5);
  // ds.unionByRank(6, 7);
  // ds.unionByRank(1, 4);

  // Example of union by size
  ds.unionBySize(0, 6);
  ds.unionBySize(0, 1);
  ds.unionBySize(7, 8);

  // Example of finding representative using findUPar
  cout << "Find parent of 3: " << ds.findUPar(3) << endl;
  cout << "Find parent of 6: " << ds.findUPar(6) << endl;
  cout << "Find parent of 8: " << ds.findUPar(8) << endl;

  return 0;
}