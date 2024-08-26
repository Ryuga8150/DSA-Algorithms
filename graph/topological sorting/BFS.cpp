#include <bits/stdc++.h>

using namespace std;

void topoSort(int nodes, vector<vector<int>> &edges)
{
  vector<vector<int>> adjList(nodes);
  vector<int> inDegree(nodes, 0);

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

    cout << node << " ";

    for (auto adjNode : adjList[node])
    {
      inDegree[adjNode]--;
      if (inDegree[adjNode] == 0)
      {
        q.push(adjNode);
      }
    }
  }
  cout << endl;
}

int main()
{
  // Test case 1
  cout << "Test Case 1: ";
  vector<vector<int>> edges1 = {{0, 1}, {1, 2}};
  topoSort(3, edges1);

  // Test case 2
  cout << "Test Case 2: ";
  vector<vector<int>> edges2 = {{0, 1}, {0, 2}, {1, 3}, {2, 3}};
  topoSort(4, edges2);

  // Test case 3
  cout << "Test Case 3: ";
  vector<vector<int>> edges3 = {{0, 1}, {2, 1}, {1, 3}};
  topoSort(4, edges3);

  // Test case 4
  cout << "Test Case 4: ";
  vector<vector<int>> edges4 = {};
  topoSort(1, edges4);

  // Test case 5
  cout << "Test Case 5: ";
  vector<vector<int>> edges5 = {{0, 0}};
  topoSort(1, edges5);

  // Test case 6
  cout << "Test Case 6: ";
  vector<vector<int>> edges6 = {{0, 1}, {2, 3}};
  topoSort(4, edges6);

  // Test case 7
  cout << "Test Case 7: ";
  vector<vector<int>> edges7 = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4}};
  topoSort(5, edges7);

  return 0;
}
