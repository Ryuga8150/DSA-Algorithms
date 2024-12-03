#include <bits/stdc++.h>
using namespace std;

bool checkEulerianPath(int n, vector<int> &inDegrees, vector<int> &outDegrees)
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

int findStartNode(int n, vector<int> &inDegrees, vector<int> &outDegrees)
{
  int startNode = -1;

  for (int i = 0; i < n; ++i)
  {
    if (outDegrees[i] - inDegrees[i] == 1)
      return i;

    //  to avoid Singleton Nodes
    if (outDegrees[i] > 0)
      startNode = i;
  }

  return startNode;
}

void dfs(int startNode, vector<int> &eulerPath, vector<vector<int>> &adjList)
{
  while (!adjList[startNode].empty())
  {
    int adjNode = adjList[startNode].back();
    adjList[startNode].pop_back();
    dfs(adjNode, eulerPath, adjList);
  }

  eulerPath.push_back(startNode);
}

vector<int> findEulerianPath(int n, vector<vector<int>> &edges)
{
  vector<vector<int>> adjList(n);

  // 1. Calculate Indegrees and OutDegrees
  vector<int> inDegrees(n, 0);
  vector<int> outDegrees(n, 0);
  for (auto edge : edges)
  {
    int src = edge[0];
    int dest = edge[1];

    adjList[src].push_back(dest);
    inDegrees[dest]++;
    outDegrees[src]++;
  }

  // 2. Check for Eulerian Path and Eulerian Circuit;
  if (!checkEulerianPath(n, inDegrees, outDegrees))
  {
    cout << "Eulerian Path Check Failed" << endl;
    return {};
  }

  // 3. Call DFS from Start Node
  int startNode = findStartNode(n, inDegrees, outDegrees);

  if (startNode == -1) // just checking
  {
    cout << "Start Node does not exist" << endl;
    return {};
  }

  cout << "SatrtNode: " << startNode << endl;

  vector<int> eulerPath;
  dfs(startNode, eulerPath, adjList);

  if (eulerPath.size() != edges.size() + 1) // since 2 vertex has 1edge
  {
    cout << "Euler Path size not equal to edges size" << endl;
    return {};
  }

  // 4. Reverse The Path
  reverse(eulerPath.begin(), eulerPath.end());

  return eulerPath;
}

int main()
{
  vector<vector<int>> edges;

  // Test Case 1: Eulerian Path Exists
  edges = {
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

  vector<int> result = findEulerianPath(7, edges);
  // Outputs path: [1, 3, 5, 6, 3, 2, 4, 3, 1, 2, 2, 4, 6]
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

  edges = {
      {0, 1},
      {1, 2},
      {1, 4},
      {1, 3},
      {2, 1},
      {4, 1}};

  result = findEulerianPath(5, edges);
  // Outputs path: [0, 1, 4, 1, 2, 1, 3]
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
