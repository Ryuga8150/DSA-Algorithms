#include <bits/stdc++.h>

using namespace std;

// Comparator function for sorting edges
bool cmp(vector<int> &v1, vector<int> &v2)
{
  return v1[2] < v2[2]; // Ensure that edges are sorted in ascending order of weights
}

// Disjoint Set (Union-Find) class
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

    return parent[node] = findUPar(parent[node]); // Path compression
  }

  void unionBySize(int u, int v)
  {
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v);

    if (ulp_u == ulp_v)
      return;

    if (size[ulp_u] < size[ulp_v])
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

// Function to find the MST of a graph
void mst(int nodes, vector<vector<int>> &edges)
{
  sort(edges.begin(), edges.end(), cmp); // Sort edges by weight

  DisjointSet ds(nodes);

  vector<vector<int>> mstEdges;
  int ans = 0;

  for (auto edge : edges)
  {
    int src = edge[0];
    int dest = edge[1];
    int wt = edge[2];

    if (ds.findUPar(src) != ds.findUPar(dest))
    {
      ds.unionBySize(src, dest);
      ans += wt;
      mstEdges.push_back(edge);
    }
  }

  cout << "Minimum Cost of MST: " << ans << endl;
  cout << "Edges in the MST:" << endl;
  for (auto &edge : mstEdges)
  {
    cout << edge[0] << " -- " << edge[1] << " == " << edge[2] << endl;
  }
}

int main()
{
  // Test case 1
  cout << "Test Case 1:" << endl;
  int nodes1 = 4;
  vector<vector<int>> edges1 = {
      {1, 2, 10},
      {1, 3, 6},
      {2, 3, 15},
      {2, 4, 5},
      {3, 4, 4}};
  mst(nodes1, edges1);

  cout << endl;

  // Test case 2
  cout << "Test Case 2:" << endl;
  int nodes2 = 5;
  vector<vector<int>> edges2 = {
      {1, 2, 9},
      {1, 3, 75},
      {2, 3, 95},
      {2, 4, 19},
      {3, 4, 35},
      {3, 5, 15},
      {4, 5, 25}};
  mst(nodes2, edges2);

  cout << endl;

  // Test case 3
  cout << "Test Case 3:" << endl;
  int nodes3 = 6;
  vector<vector<int>> edges3 = {
      {1, 2, 7},
      {1, 3, 9},
      {1, 4, 14},
      {2, 3, 10},
      {2, 4, 15},
      {3, 4, 11},
      {3, 5, 2},
      {4, 5, 6},
      {4, 6, 9},
      {5, 6, 9}};
  mst(nodes3, edges3);

  return 0;
}
