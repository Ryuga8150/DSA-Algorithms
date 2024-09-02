#include <bits/stdc++.h>
using namespace std;

// Function to generate the adjacency matrix from the edge list
vector<vector<int>> getAdjMatrix(int nodes, vector<vector<int>> &edges)
{
  vector<vector<int>> adjMatrix(nodes, vector<int>(nodes, INT_MAX));

  for (auto edge : edges)
  {
    int src = edge[0];
    int dest = edge[1];
    int wt = edge[2];
    adjMatrix[src][dest] = wt;
  }

  // Distance from a node to itself is zero
  for (int i = 0; i < nodes; ++i)
  {
    adjMatrix[i][i] = 0;
  }

  return adjMatrix;
}

// Floyd-Warshall algorithm to find shortest paths
void shortestPath(int nodes, vector<vector<int>> &edges)
{
  vector<vector<int>> dist = getAdjMatrix(nodes, edges);

  for (int k = 0; k < nodes; ++k)
  {
    for (int i = 0; i < nodes; ++i)
    {
      for (int j = 0; j < nodes; ++j)
      {
        if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
          continue;

        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  // Check for negative weight cycles
  for (int i = 0; i < nodes; ++i)
  {
    if (dist[i][i] < 0)
    {
      cout << "Negative Cycle Exists" << endl;
      return;
    }
  }

  // Print shortest path distances
  cout << "Shortest Path Distances:" << endl;
  for (int i = 0; i < nodes; ++i)
  {
    for (int j = 0; j < nodes; ++j)
    {
      if (dist[i][j] == INT_MAX)
        cout << "INF" << " ";
      else
        cout << dist[i][j] << " ";
    }
    cout << endl;
  }
}

int main()
{
  // Sample Case 1: Basic Test Case (No Negative Cycles)
  cout << "Sample Case 1:" << endl;
  vector<vector<int>> edges1 = {{0, 1, 1}, {1, 2, 2}, {2, 3, 1}, {0, 2, 4}, {1, 3, 5}};
  int nodes1 = 4;
  shortestPath(nodes1, edges1);
  cout << endl;

  // Sample Case 2: Graph with Negative Weights but No Negative Cycles
  cout << "Sample Case 2:" << endl;
  vector<vector<int>> edges2 = {{0, 1, -1}, {1, 2, -2}, {2, 0, -3}};
  int nodes2 = 3;
  shortestPath(nodes2, edges2);
  cout << endl;

  // Sample Case 3: Graph with Negative Weight Cycle
  cout << "Sample Case 3:" << endl;
  vector<vector<int>> edges3 = {{0, 1, 1}, {1, 2, -1}, {2, 0, -1}};
  int nodes3 = 3;
  shortestPath(nodes3, edges3);
  cout << endl;

  // Sample Case 4: Graph with No Path from Source to Destination
  cout << "Sample Case 4:" << endl;
  vector<vector<int>> edges4 = {{0, 1, 5}, {1, 2, 5}, {2, 3, 5}};
  int nodes4 = 4;
  shortestPath(nodes4, edges4);
  cout << endl;

  // Sample Case 5: Disconnected Graph
  cout << "Sample Case 5:" << endl;
  vector<vector<int>> edges5 = {{0, 1, 2}, {1, 2, 3}, {3, 4, 1}};
  int nodes5 = 5;
  shortestPath(nodes5, edges5);
  cout << endl;

  // Sample Case 6: Self Loop and Zero Weights
  cout << "Sample Case 6:" << endl;
  vector<vector<int>> edges6 = {{0, 1, 0}, {1, 0, 0}};
  int nodes6 = 2;
  shortestPath(nodes6, edges6);
  cout << endl;

  return 0;
}
