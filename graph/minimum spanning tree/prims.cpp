#include <bits/stdc++.h>

using namespace std;

// Function to compute MST using Prim's algorithm
void mst(int nodes, int source, vector<vector<pair<int, int>>> &adjList)
{
  vector<int> parents(nodes, -1);
  vector<int> visited(nodes, 0);
  priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

  // wt, node, parent
  pq.push({0, source, -1});
  visited[source] = 1;

  int ans = 0;
  while (!pq.empty())
  {
    int wt = pq.top()[0];
    int node = pq.top()[1];
    int parent = pq.top()[2];

    pq.pop();

    parents[node] = parent;
    nodes--;

    if (nodes == 0)
    {
      ans = wt;
      break;
    }

    for (auto adj : adjList[node])
    {
      int adjNode = adj.first;
      int edgeWt = adj.second;

      if (!visited[adjNode])
      {
        pq.push({edgeWt + wt, adjNode, node});
        visited[adjNode] = 1; // Mark node as visited when added to the priority queue
      }
    }
  }
  cout << "Total weight of MST: " << ans << endl;

  // Print MST edges
  cout << "Edges in the MST:" << endl;
  for (int i = 0; i < parents.size(); i++)
  {
    if (parents[i] != -1)
    {
      cout << parents[i] << " - " << i << endl;
    }
  }
}

int main()
{
  // Test case 1
  {
    int nodes = 4;
    vector<vector<pair<int, int>>> adjList = {
        {{1, 1}, {4, 2}}, // Edges from node 0
        {{1, 0}, {2, 2}}, // Edges from node 1
        {{4, 0}, {2, 1}}, // Edges from node 2
        {}                // Edges from node 3 (none in this example)
    };
    int source = 0;
    cout << "Test case with " << nodes << " nodes and source node " << source << endl;
    mst(nodes, source, adjList);
    cout << "----------------------" << endl;
  }

  // Test case 2
  {
    int nodes = 5;
    vector<vector<pair<int, int>>> adjList = {
        {{2, 1}, {4, 2}},         // Edges from node 0
        {{2, 0}, {3, 2}},         // Edges from node 1
        {{4, 0}, {3, 1}, {1, 3}}, // Edges from node 2
        {{3, 1}, {1, 2}},         // Edges from node 3
        {}                        // Edges from node 4 (none in this example)
    };
    int source = 0;
    cout << "Test case with " << nodes << " nodes and source node " << source << endl;
    mst(nodes, source, adjList);
    cout << "----------------------" << endl;
  }

  return 0;
}