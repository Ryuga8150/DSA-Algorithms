#include <bits/stdc++.h>

using namespace std;

void bfs(int src, vector<vector<int>> &adjList)
{
  queue<int> q;
  int nodes = adjList.size();
  vector<int> visited(nodes, 0);

  q.push(src);
  visited[src] = 1;

  while (!q.empty())
  {
    int count = q.size();

    for (int k = 0; k < count; ++k)
    {
      int node = q.front();
      q.pop();
      for (auto adjNode : adjList[node])
      {
        if (!visited[adjNode])
        {
          q.push(adjNode);
          visited[adjNode] = 1;
        }
      }
    }
  }
}

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
    int source = 0;
    bfs(source, adjList);
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
    int source = 0;
    bfs(source, adjList);
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
    int source = 0;
    bfs(source, adjList);
  }

  return 0;
}
