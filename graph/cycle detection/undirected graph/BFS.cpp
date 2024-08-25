#include <bits/stdc++.h>

using namespace std;

bool checkCycle(int src, vector<vector<int>> &adjList, vector<int> &visited)
{
  queue<vector<int>> q;
  q.push({src, -1});
  visited[src] = 1;

  while (!q.empty())
  {
    int count = q.size();

    for (int k = 0; k < count; ++k)
    {
      int node = q.front()[0];
      int parent = q.front()[1];

      q.pop();
      for (auto adjNode : adjList[node])
      {
        if (!visited[adjNode])
        {
          q.push({adjNode, node});
          visited[adjNode] = 1;
        }
        else if (adjNode != parent)
        {
          return true;
        }
      }
    }
  }

  return false;
}

int main()
{
  // Define the test cases
  vector<tuple<int, vector<pair<int, int>>>> testCases = {
      {3, {{0, 1}, {1, 2}, {2, 0}}},        // Test Case 1: Simple cycle
      {4, {{0, 1}, {1, 2}, {2, 3}}},        // Test Case 2: No cycle
      {5, {{0, 1}, {1, 2}, {2, 0}, {3, 4}}} // Test Case 3: Cycle in one component
  };

  // Process each test case
  for (const auto &testCase : testCases)
  {
    int nodes;
    vector<pair<int, int>> edges;
    tie(nodes, edges) = testCase;

    // Initialize adjacency list
    vector<vector<int>> adjList(nodes);
    vector<int> visited(nodes, 0);

    // Fill the adjacency list from edges
    for (const auto &edge : edges)
    {
      int u = edge.first;
      int v = edge.second;
      adjList[u].push_back(v);
      adjList[v].push_back(u);
    }

    // Check for cycles in the graph
    bool hasCycle = false;
    for (int i = 0; i < nodes; ++i)
    {
      if (!visited[i])
      {
        if (checkCycle(i, adjList, visited))
        {
          hasCycle = true;
          break;
        }
      }
    }

    // Output the result for the current test case
    if (hasCycle)
      cout << "Cycle detected" << endl;
    else
      cout << "No cycle detected" << endl;
  }

  return 0;
}
