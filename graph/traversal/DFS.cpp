#include <bits/stdc++.h>

using namespace std;

// DFS function

void dfs(int src, vector<int> &visited, vector<vector<int>> &adjList)
{
  visited[src] = 1;

  for (auto adjNode : adjList[src])
  {
    if (!visited[adjNode])
    {
      dfs(adjNode, visited, adjList);
    }
  }
}

// Main function
int main()
{
  // Test case 1: Simple directed graph
  {
    vector<vector<int>> adjList(5); // Graph with 5 nodes
    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4}};

    for (auto edge : edges)
    {
      int src = edge.first;
      int dest = edge.second;
      adjList[src].push_back(dest);
    }

    cout << "Test Case 1:" << endl;
    vector<int> visited(5, 0); // Initialize visited array
    int source = 0;
    dfs(source, visited, adjList);
    cout << endl;
  }

  // Test case 2: Directed graph with a cycle
  {
    vector<vector<int>> adjList(4); // Graph with 4 nodes
    vector<pair<int, int>> edges = {{0, 1}, {1, 2}, {2, 0}, {2, 3}};

    for (auto edge : edges)
    {
      int src = edge.first;
      int dest = edge.second;
      adjList[src].push_back(dest);
    }

    cout << "Test Case 2:" << endl;
    vector<int> visited(4, 0); // Initialize visited array
    int source = 0;
    dfs(source, visited, adjList);
    cout << endl;
  }

  // Test case 3: Disconnected directed graph
  {
    vector<vector<int>> adjList(6); // Graph with 6 nodes
    vector<pair<int, int>> edges = {{0, 1}, {1, 2}, {3, 4}, {4, 5}};

    for (auto edge : edges)
    {
      int src = edge.first;
      int dest = edge.second;
      adjList[src].push_back(dest);
    }

    cout << "Test Case 3:" << endl;
    vector<int> visited(6, 0); // Initialize visited array
    int source = 0;
    dfs(source, visited, adjList);
    cout << endl;
  }

  return 0;
}
