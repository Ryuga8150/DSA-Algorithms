#include <bits/stdc++.h>
using namespace std;

template <typename Type>
class Node
{
public:
  Type seg;
  Type prefix;
  Type suffix;
  Type sum;

  Node()
  {
    seg = prefix = suffix = sum = 0;
  }
};

template <typename Type>
class SegmentTree
{
private:
  vector<Node<Type>> segTree;
  vector<Type> nums;

public:
  SegmentTree(vector<Type> &arr)
  {
    Type size = arr.size();
    segTree.resize(4 * size);
    nums = arr;
  }

  void build(int index, int low, int high)
  {
    if (low == high)
    {
      segTree[index].seg = nums[low];
      segTree[index].prefix = nums[low];
      segTree[index].suffix = nums[low];
      segTree[index].sum = nums[low];
      return;
    }

    int mid = low + (high - low) / 2;

    int leftNodeIndex = 2 * index + 1;
    int rightNodeIndex = 2 * index + 2;

    build(leftNodeIndex, low, mid);
    build(rightNodeIndex, mid + 1, high);

    segTree[index].seg = max(segTree[leftNodeIndex].suffix + segTree[rightNodeIndex].prefix, max(segTree[leftNodeIndex].seg, segTree[rightNodeIndex].seg));

    segTree[index].prefix = max(segTree[leftNodeIndex].prefix, segTree[leftNodeIndex].sum + segTree[rightNodeIndex].prefix);

    segTree[index].suffix = max(segTree[rightNodeIndex].suffix, segTree[rightNodeIndex].sum + segTree[leftNodeIndex].suffix);

    segTree[index].sum = segTree[leftNodeIndex].sum + segTree[rightNodeIndex].sum;
  }

  void update(int index, int low, int high, int updateIndex, Type val)
  {
    if (low == high)
    {
      segTree[index].seg = val;
      segTree[index].prefix = val;
      segTree[index].suffix = val;
      segTree[index].sum = val;
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

    segTree[index].seg = max(segTree[leftNodeIndex].suffix + segTree[rightNodeIndex].prefix, max(segTree[leftNodeIndex].seg, segTree[rightNodeIndex].seg));

    segTree[index].prefix = max(segTree[leftNodeIndex].prefix, segTree[leftNodeIndex].sum + segTree[rightNodeIndex].prefix);

    segTree[index].suffix = max(segTree[rightNodeIndex].suffix, segTree[rightNodeIndex].sum + segTree[leftNodeIndex].suffix);

    segTree[index].sum = segTree[leftNodeIndex].sum + segTree[rightNodeIndex].sum;
  }

  void maxmSegment()
  {
    int val = segTree[0].seg;
    return val >= 0 ? val : 0;
  }
};