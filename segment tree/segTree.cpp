#include <bits/stdc++.h>
using namespace std;

template <typename Type>
class SegmentTree
{
private:
  vector<Type> segTree;
  vector<Type> nums;

public:
  SegmentTree(int n, vector<Type> &arr)
  {
    segTree.resize(4 * n);
    nums = arr;
  }

  void build(int index, int low, int high)
  {
    if (low == high)
    {
      segTree[index] = nums[low];
      return;
    }

    int mid = low + (high - low) / 2;

    int leftNodeIndex = 2 * index + 1;
    int rightNodeIndex = 2 * index + 2;

    build(leftNodeIndex, low, mid);
    build(rightNodeIndex, mid + 1, high);

    segTree[index] = segTree[leftNodeIndex] + segTree[rightNodeIndex];
  }

  void update(int index, int low, int high, int updateIndex, Type val)
  {
    if (low == high)
    {
      segTree[index] = val;
      return;
    }

    int mid = low + (high - low) / 2;

    int leftNodeIndex = 2 * index + 1;
    int rightNodeIndex = 2 * index + 2;

    if (updateIndex <= mid)
    {
      update(leftNodeIndex, low, mid, updateIndex, val);
    }
    else
    {
      update(rightNodeIndex, mid + 1, high, updateIndex, val);
    }

    segTree[index] = segTree[leftNodeIndex] + segTree[rightNodeIndex];
  }

  Type query(int index, int low, int high, int queryLow, int queryHigh)
  {
    if (low > queryHigh || high < queryLow)
      return 0;

    if (low >= queryLow && high <= queryHigh)
      return segTree[index];

    int mid = low + (high - low) / 2;

    int leftNodeIndex = 2 * index + 1;
    int rightNodeIndex = 2 * index + 2;

    Type leftVal = query(leftNodeIndex, low, mid, queryLow, queryHigh);
    Type rightVal = query(rightNodeIndex, mid + 1, high, queryLow, queryHigh);

    return leftVal + rightVal;
  }
};

int main()
{
  // Initialize SegmentTree with integer type and array
  vector<int> arr = {1, 3, 5, 7, 9};
  int n = arr.size();
  SegmentTree<int> st(n, arr);
  st.build(0, 0, n - 1);

  // Define array of queries
  vector<vector<int>> queries = {
      {1, 1, 3}, // Type 1: Range sum query [1, 3]
      {2, 2, 6}, // Type 2: Update index 2 to value 6
      {1, 1, 3}, // Type 1: Range sum query [1, 3] after update
      {1, 0, 4}, // Type 1: Range sum query [0, 4]
      {2, 3, 3}, // Type 2: Update index 3 to value 3
      {1, 2, 4}, // Type 1: Range sum query [2, 4] after update
      {1, 0, 0}, // Type 1: Range sum query [0, 0]
      {2, 0, 5}, // Type 2: Update index 0 to value 5
      {1, 0, 0}  // Type 1: Range sum query [0, 0] after update
  };

  // Process each query for integer SegmentTree
  for (auto query : queries)
  {
    int type = query[0];
    if (type == 1)
    {
      int l = query[1];
      int r = query[2];
      int result = st.query(0, 0, n - 1, l, r);
      cout << "Range sum query [" << l << ", " << r << "]: " << result << endl;
    }
    else if (type == 2)
    {
      int updateIndex = query[1];
      int updateValue = query[2];
      st.update(0, 0, n - 1, updateIndex, updateValue);
      cout << "Updated index " << updateIndex << " to value " << updateValue << endl;
    }
  }

  return 0;
}
