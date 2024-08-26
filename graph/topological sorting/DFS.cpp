#include <bits/stdc++.h>

using namespace std;

// should be a dag
// else will give wrong o/p
// like test case 5
void dfs(int src, stack<int> &st, vector<int> &visited, vector<vector<int>> &adjList)
{
  visited[src] = 1;

  for (auto adjNode : adjList[src])
  {
    if (!visited[adjNode])
    {
      dfs(adjNode, st, visited, adjList);
    }
  }

  st.push(src);
}

void topoSort(int nodes, vector<vector<int>> &edges)
{
  vector<vector<int>> adjList(nodes);

  for (auto edge : edges)
  {
    int src = edge[0];
    int dest = edge[1];

    adjList[src].push_back(dest);
  }

  stack<int> st;
  vector<int> visited(nodes, 0);

  for (int i = 0; i < nodes; ++i)
  {
    if (!visited[i])
      dfs(i, st, visited, adjList);
  }

  while (!st.empty())
  {
    int node = st.top();
    st.pop();

    cout << node << " ";
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
