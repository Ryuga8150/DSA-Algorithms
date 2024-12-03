#include <bits/stdc++.h>
using namespace std;

class EulerianPath
{
private:
  vector<vector<int>> adjList;
  vector<int> inDegrees, outDegrees;

  // Helper function to check if Eulerian Path exists
  bool checkEulerianPath(int n)
  {
    int startNodes = 0, endNodes = 0;

    for (int i = 0; i < n; ++i)
    {
      if (abs(outDegrees[i] - inDegrees[i]) > 1)
        return false;

      if (outDegrees[i] - inDegrees[i] == 1)
        startNodes++;

      if (inDegrees[i] - outDegrees[i] == 1)
        endNodes++;
    }

    return (startNodes == 0 && endNodes == 0) || (startNodes == 1 && endNodes == 1);
  }

  // Helper function to find the starting node for DFS
  int findStartNode(int n)
  {
    int startNode = -1;

    for (int i = 0; i < n; ++i)
    {
      if (outDegrees[i] - inDegrees[i] == 1)
        return i;

      // To avoid singleton nodes
      if (outDegrees[i] > 0)
        startNode = i;
    }

    return startNode;
  }

  // DFS to construct the Eulerian Path
  void dfs(int startNode, vector<int> &eulerPath)
  {
    while (!adjList[startNode].empty())
    {
      int adjNode = adjList[startNode].back();
      adjList[startNode].pop_back();
      dfs(adjNode, eulerPath);
    }

    eulerPath.push_back(startNode);
  }

public:
  // Constructor to initialize graph properties using edges
  EulerianPath(int n, vector<vector<int>> &edges)
  {
    adjList.resize(n);
    inDegrees.resize(n, 0);
    outDegrees.resize(n, 0);

    // Construct adjacency list and calculate in/out degrees
    for (auto edge : edges)
    {
      int src = edge[0];
      int dest = edge[1];
      adjList[src].push_back(dest);
      inDegrees[dest]++;
      outDegrees[src]++;
    }
  }

  // Constructor to initialize graph properties using adjacency list
  EulerianPath(vector<vector<int>> &adjListInput)
  {
    int n = adjListInput.size();
    adjList = adjListInput;
    inDegrees.resize(n, 0);
    outDegrees.resize(n, 0);

    // Calculate in-degrees and out-degrees from adjacency list
    for (int i = 0; i < n; ++i)
    {
      for (int neighbor : adjList[i])
      {
        outDegrees[i]++;
        inDegrees[neighbor]++;
      }
    }
  }

  // Function to find the Eulerian Path
  vector<int> findPath(int n)
  {
    // 1. Check for Eulerian Path
    if (!checkEulerianPath(n))
    {
      cout << "Eulerian Path Check Failed" << endl;
      return {};
    }

    // 2. Find Start Node
    int startNode = findStartNode(n);
    if (startNode == -1)
    {
      cout << "Start Node does not exist" << endl;
      return {};
    }

    // 3. Perform DFS to construct the Eulerian Path
    vector<int> eulerPath;
    dfs(startNode, eulerPath);

    if (eulerPath.size() != accumulate(outDegrees.begin(), outDegrees.end(), 0) + 1)
    {
      cout << "Euler Path size not equal to edges size" << endl;
      return {};
    }

    // 4. Reverse the path
    reverse(eulerPath.begin(), eulerPath.end());
    return eulerPath;
  }
};

int main()
{
  // Test Case 1: Eulerian Path Exists using edges
  vector<vector<int>> edges = {
      {1, 2},
      {1, 3},
      {2, 2},
      {2, 4},
      {2, 4},
      {3, 1},
      {3, 2},
      {3, 5},
      {4, 3},
      {4, 6},
      {5, 6},
      {6, 3},
  };

  EulerianPath ep1(7, edges);
  vector<int> result = ep1.findPath(7);

  if (!result.empty())
  {
    cout << "Test Case 1: Eulerian Path Found:\n";
    for (int node : result)
      cout << node << " ";
    cout << endl;
  }
  else
  {
    cout << "Test Case 1: No Eulerian Path.\n";
  }

  cout << endl;

  // Test Case 2: Eulerian Path Exists using adjacency list
  vector<vector<int>> adjList = {
      {1},       // Node 0 -> Node 1
      {2, 4, 3}, // Node 1 -> Nodes 2, 4, 3
      {1},       // Node 2 -> Node 1
      {},        // Node 3 -> No edges
      {1},       // Node 4 -> Node 1
      {}         // Node 5 -> No edges
  };

  EulerianPath ep2(adjList);
  result = ep2.findPath(6);

  if (!result.empty())
  {
    cout << "Test Case 2: Eulerian Path Found:\n";
    for (int node : result)
      cout << node << " ";
    cout << endl;
  }
  else
  {
    cout << "Test Case 2: No Eulerian Path.\n";
  }

  return 0;
}
