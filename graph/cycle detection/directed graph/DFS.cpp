#include <bits/stdc++.h>

using namespace std;

// Check cycle using DFS
bool dfs(int src, vector<int> &path, vector<int> &visited, vector<vector<int>> &adjList)
{
  visited[src] = 1;
  path[src] = 1;

  for (auto adjNode : adjList[src])
  {
    if (!visited[adjNode])
    {
      if (dfs(adjNode, path, visited, adjList))
      {
        return true;
      }
    }
    else if (path[adjNode])
    {
      return true;
    }
  }

  path[src] = 0;

  return false;
}

bool hasCycle(vector<vector<int>> &adjList, int n)
{
  vector<int> visited(n, 0);
  vector<int> path(n, 0);

  for (int i = 0; i < n; ++i)
  {
    if (!visited[i])
    {
      if (dfs(i, path, visited, adjList))
      {
        return true;
      }
    }
  }
  return false;
}

void testCycleDetection(vector<vector<int>> &adjList, int expectedResult)
{
  int n = adjList.size();
  bool result = hasCycle(adjList, n);
  cout << "Cycle detected: " << (result ? "Yes" : "No") << endl;
  cout << "Expected: " << (expectedResult ? "Yes" : "No") << endl;
  cout << (result == expectedResult ? "Test Passed" : "Test Failed") << endl;
}

int main()
{
  // Test Case 1: No Cycle
  vector<vector<int>> adjList1 = {
      {1}, // 0
      {2}, // 1
      {}   // 2
  };
  testCycleDetection(adjList1, false);

  // Test Case 2: Single Cycle
  vector<vector<int>> adjList2 = {
      {1}, // 0
      {2}, // 1
      {0}  // 2
  };
  testCycleDetection(adjList2, true);

  // Test Case 3: Multiple Cycles
  vector<vector<int>> adjList3 = {
      {1, 4}, // 0
      {2},    // 1
      {3},    // 2
      {4},    // 3
      {}      // 4
  };
  testCycleDetection(adjList3, true);

  // Test Case 4: Disconnected Graph
  vector<vector<int>> adjList4 = {
      {1}, // 0
      {2}, // 1
      {},  // 2
      {}   // 3
  };
  testCycleDetection(adjList4, false);

  // Test Case 5: Self Loop
  vector<vector<int>> adjList5 = {
      {1}, // 0
      {0}  // 1
  };
  testCycleDetection(adjList5, true);

  // Test Case 6: Complex Graph
  vector<vector<int>> adjList6 = {
      {1, 4}, // 0
      {2},    // 1
      {3},    // 2
      {5},    // 3
      {},     // 4
      {1}     // 5
  };
  testCycleDetection(adjList6, true);

  return 0;
}
