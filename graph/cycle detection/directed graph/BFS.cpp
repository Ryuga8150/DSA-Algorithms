#include <bits/stdc++.h>

using namespace std;

// Function to check if there's a cycle in the directed graph
bool checkCycle(int nodes, vector<vector<int>> &edges)
{
  vector<vector<int>> adjList(nodes);
  vector<int> inDegree(nodes, 0);

  // Build the adjacency list and compute in-degrees
  for (auto edge : edges)
  {
    int src = edge[0];
    int dest = edge[1];
    adjList[src].push_back(dest);
    inDegree[dest]++;
  }

  queue<int> q;
  for (int i = 0; i < nodes; ++i)
  {
    if (!inDegree[i])
    {
      q.push(i);
    }
  }

  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    nodes--;

    for (auto adjNode : adjList[node])
    {
      inDegree[adjNode]--;
      if (inDegree[adjNode] == 0)
      {
        q.push(adjNode);
      }
    }
  }

  // If count of processed nodes is not equal to total nodes, there's a cycle
  return nodes > 0;
}

int main()
{
  // Test Case 1: No Cycle
  {
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2}};
    int nodes = 3;
    cout << "Test Case 1: " << (checkCycle(nodes, edges) ? "Cycle Detected" : "No Cycle") << endl;
  }

  // Test Case 2: Single Cycle
  {
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 0}};
    int nodes = 3;
    cout << "Test Case 2: " << (checkCycle(nodes, edges) ? "Cycle Detected" : "No Cycle") << endl;
  }

  // Test Case 3: Multiple Cycles
  {
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 1}};
    int nodes = 4;
    cout << "Test Case 3: " << (checkCycle(nodes, edges) ? "Cycle Detected" : "No Cycle") << endl;
  }

  // Test Case 4: Disconnected Graph
  {
    vector<vector<int>> edges = {
        {0, 1},
        {2, 3}};
    int nodes = 4;
    cout << "Test Case 4: " << (checkCycle(nodes, edges) ? "Cycle Detected" : "No Cycle") << endl;
  }

  // Test Case 5: Self Loop
  {
    vector<vector<int>> edges = {
        {0, 1},
        {1, 1}};
    int nodes = 2;
    cout << "Test Case 5: " << (checkCycle(nodes, edges) ? "Cycle Detected" : "No Cycle") << endl;
  }

  // Test Case 6: Complex Graph
  {
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 2}};
    int nodes = 5;
    cout << "Test Case 6: " << (checkCycle(nodes, edges) ? "Cycle Detected" : "No Cycle") << endl;
  }

  return 0;
}
