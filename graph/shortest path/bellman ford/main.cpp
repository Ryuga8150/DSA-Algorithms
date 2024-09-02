#include <bits/stdc++.h>
using namespace std;

// Function to find the shortest path using Bellman-Ford algorithm
int shortestPath(int nodes, int source, int destination, vector<vector<int>> &edges)
{
  vector<int> dist(nodes, INT_MAX);
  dist[source] = 0;

  // Relax all edges up to (nodes - 1) times
  for (int i = 0; i < nodes - 1; ++i)
  {
    for (auto edge : edges)
    {
      int src = edge[0];
      int dest = edge[1];
      int wt = edge[2];

      if (dist[src] != INT_MAX && dist[src] + wt < dist[dest])
      {
        dist[dest] = dist[src] + wt;
      }
    }
  }

  // Check for negative weight cycles
  for (auto edge : edges)
  {
    int src = edge[0];
    int dest = edge[1];
    int wt = edge[2];

    if (dist[src] != INT_MAX && dist[src] + wt < dist[dest])
    {
      cout << "Negative Cycle exists" << endl;
      return -1;
    }
  }

  return dist[destination] != INT_MAX ? dist[destination] : -1;
}

int main()
{
  // Sample Case 1: Basic Test Case (No Negative Cycles)
  cout << "Sample Case 1: " << endl;
  vector<vector<int>> edges1 = {{0, 1, 1}, {1, 2, 2}, {2, 3, 1}, {0, 2, 4}, {1, 3, 5}};
  int nodes1 = 4;
  int source1 = 0;
  int destination1 = 3;
  cout << "Shortest Path from " << source1 << " to " << destination1 << ": " << shortestPath(nodes1, source1, destination1, edges1) << endl;

  // Sample Case 2: Graph with Negative Weights but No Negative Cycles
  cout << "Sample Case 2: " << endl;
  vector<vector<int>> edges2 = {{0, 1, -1}, {1, 2, -2}, {2, 0, -3}};
  int nodes2 = 3;
  int source2 = 0;
  int destination2 = 2;
  cout << "Shortest Path from " << source2 << " to " << destination2 << ": " << shortestPath(nodes2, source2, destination2, edges2) << endl;

  // Sample Case 3: Graph with Negative Weight Cycle
  cout << "Sample Case 3: " << endl;
  vector<vector<int>> edges3 = {{0, 1, 1}, {1, 2, -1}, {2, 0, -1}};
  int nodes3 = 3;
  int source3 = 0;
  int destination3 = 2;
  cout << "Shortest Path from " << source3 << " to " << destination3 << ": " << shortestPath(nodes3, source3, destination3, edges3) << endl;

  // Sample Case 4: Graph with No Path from Source to Destination
  cout << "Sample Case 4: " << endl;
  vector<vector<int>> edges4 = {{0, 1, 5}, {1, 2, 5}, {2, 3, 5}};
  int nodes4 = 4;
  int source4 = 0;
  int destination4 = 3;
  cout << "Shortest Path from " << source4 << " to " << destination4 << ": " << shortestPath(nodes4, source4, destination4, edges4) << endl;

  // Sample Case 5: Disconnected Graph
  cout << "Sample Case 5: " << endl;
  vector<vector<int>> edges5 = {{0, 1, 2}, {1, 2, 3}, {3, 4, 1}};
  int nodes5 = 5;
  int source5 = 0;
  int destination5 = 4;
  cout << "Shortest Path from " << source5 << " to " << destination5 << ": " << shortestPath(nodes5, source5, destination5, edges5) << endl;

  // Sample Case 6: Self Loop and Zero Weights
  cout << "Sample Case 6: " << endl;
  vector<vector<int>> edges6 = {{0, 1, 0}, {1, 0, 0}};
  int nodes6 = 2;
  int source6 = 0;
  int destination6 = 1;
  cout << "Shortest Path from " << source6 << " to " << destination6 << ": " << shortestPath(nodes6, source6, destination6, edges6) << endl;

  return 0;
}
