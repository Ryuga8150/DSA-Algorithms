#include <bits/stdc++.h>
using namespace std;

int shortestPath(int source, int destination, vector<vector<pair<int, int>>> adjList)
{
  int nodes = adjList.size();

  vector<int> distance(nodes, INT_MAX);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

  distance[source] = 0;
  pq.push({0, source});

  while (!pq.empty())
  {
    int dist = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    for (auto adj : adjList[node])
    {
      int adjNode = adj.first;
      int edgeWt = adj.second;

      if (dist + edgeWt < distance[adjNode])
      {
        distance[adjNode] = dist + edgeWt;
        pq.push({distance[adjNode], adjNode});
      }
    }
  }

  return distance[destination] == INT_MAX ? -1 : distance[destination];
}

int main()
{
  // Sample Test Case 1
  vector<vector<pair<int, int>>> adjList1 = {
      {{1, 4}, {2, 1}},          // Node 0
      {{2, 2}, {3, 5}},          // Node 1
      {{1, 2}, {3, 8}, {4, 10}}, // Node 2
      {{4, 2}},                  // Node 3
      {}                         // Node 4
  };

  int source1 = 0;
  int destination1 = 4;

  int result1 = shortestPath(source1, destination1, adjList1);
  cout << "Shortest path from " << source1 << " to " << destination1 << " is " << result1 << endl;

  // Sample Test Case 2
  vector<vector<pair<int, int>>> adjList2 = {
      {{1, 1}, {2, 4}}, // Node 0
      {{2, 2}, {3, 6}}, // Node 1
      {{3, 1}},         // Node 2
      {}                // Node 3
  };

  int source2 = 0;
  int destination2 = 3;

  int result2 = shortestPath(source2, destination2, adjList2);
  cout << "Shortest path from " << source2 << " to " << destination2 << " is " << result2 << endl;

  // Sample Test Case 3 (No path)
  vector<vector<pair<int, int>>> adjList3 = {
      {{1, 5}}, // Node 0
      {{2, 5}}, // Node 1
      {}        // Node 2
  };

  int source3 = 0;
  int destination3 = 2;

  int result3 = shortestPath(source3, destination3, adjList3);
  cout << "Shortest path from " << source3 << " to " << destination3 << " is " << (result3 == -1 ? "No path" : to_string(result3)) << endl;

  return 0;
}
