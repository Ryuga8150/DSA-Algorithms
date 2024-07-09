#include <bits/stdc++.h>
using namespace std;

template <typename Type>
class SegmentTree
{
private:
  vector<Type> segTree;
  vector<Type> lazyTree;
  vector<Type> nums;

public:
  SegmentTree(int n, vector<Type> &arr)
  {
    segTree.resize(4 * n);
    lazyTree.resize(4 * n, 0);
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

  // logN
  void updateLazy(int index, int low, int high, int updateLow, int updateHigh, Type val)
  {

    int leftNodeIndex = 2 * index + 1;
    int rightNodeIndex = 2 * index + 2;

    if (lazyTree[index] != 0)
    {
      segTree[index] += (high - low + 1) * lazyTree[index];

      if (low != high)
      {
        lazyTree[leftNodeIndex] += lazyTree[index];
        lazyTree[rightNodeIndex] += lazyTree[index];
      }
      lazyTree[index] = 0;
    }

    if (low > updateHigh || high < updateLow)
      return;

    if (low >= updateLow && high <= updateHigh)
    {
      segTree[index] += (high - low + 1) * val;
      if (low != high)
      {
        lazyTree[leftNodeIndex] += val;
        lazyTree[rightNodeIndex] += val;
      }

      return;
    }

    int mid = low + (high - low) / 2;

    updateLazy(leftNodeIndex, low, mid, updateLow, updateHigh, val);
    updateLazy(rightNodeIndex, mid + 1, high, updateLow, updateHigh, val);

    segTree[index] = segTree[leftNodeIndex] + segTree[rightNodeIndex];
  }

  Type queryLazy(int index, int low, int high, int queryLow, int queryHigh)
  {
    int leftNodeIndex = 2 * index + 1;
    int rightNodeIndex = 2 * index + 2;

    if (lazyTree[index] != 0)
    {
      segTree[index] += (high - low + 1) * lazyTree[index];

      if (low != high)
      {
        lazyTree[leftNodeIndex] += lazyTree[index];
        lazyTree[rightNodeIndex] += lazyTree[index];
      }
      lazyTree[index] = 0;
    }

    if (low > queryHigh || high < queryLow)
      return 0;

    if (low >= queryLow && high <= queryHigh)
    {
      return segTree[index];
    }

    int mid = low + (high - low) / 2;

    Type leftVal = queryLazy(leftNodeIndex, low, mid, queryLow, queryHigh);
    Type rightVal = queryLazy(rightNodeIndex, mid + 1, high, queryLow, queryHigh);

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

  // Define array of queries (updated for range updates)
  vector<vector<int>> queries = {
      {1, 1, 3},    // Type 1: Range sum query [1, 3]
      {2, 1, 3, 6}, // Type 2: Update range [1, 3] to value 6
      {1, 1, 3},    // Type 1: Range sum query [1, 3] after update
      {1, 0, 4},    // Type 1: Range sum query [0, 4]
      {2, 3, 3, 3}, // Type 2: Update index 3 to value 3
      {1, 2, 4},    // Type 1: Range sum query [2, 4] after update
      {1, 0, 0},    // Type 1: Range sum query [0, 0]
      {2, 0, 4, 5}, // Type 2: Update range [0, 4] to value 5
      {1, 0, 0}     // Type 1: Range sum query [0, 0] after update
  };

  // Process each query for integer SegmentTree
  for (size_t i = 0; i < queries.size(); ++i)
  {
    int type = queries[i][0];
    if (type == 1)
    {
      int l = queries[i][1], r = queries[i][2];
      // Perform range sum query [l, r]
      cout << "Query " << i + 1 << ": Sum query [" << l << ", " << r << "] = " << st.queryLazy(0, 0, n - 1, l, r) << endl;
    }
    else if (type == 2)
    {
      int l = queries[i][1], r = queries[i][2], val = queries[i][3];
      // Update range [l, r] to value val
      st.updateLazy(0, 0, n - 1, l, r, val);
      cout << "Query " << i + 1 << ": Updated range [" << l << ", " << r << "] to " << val << endl;
    }
  }

  return 0;
}
