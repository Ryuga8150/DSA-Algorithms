#include <bits/stdc++.h>
using namespace std;

/*
  CODE is for 1 based indexing

  to adapt to 0 based indexing
  in each function which receives index as argument do a +1

  CODE synopsis
  -index --> 2's complement

   steps to find update indices
   1. 2's complement
   2. & with original index
   3. add with original index

   steps to find sum indices
   1. 2's complement
   2. & with original index
   3. sutract with original index
 */
class FenwickTree
{
private:
  vector<int> fenTree;

public:
  FenwickTree(int n)
  {
    fenTree.resize(n + 1, 0); // 1-based indexing
  }

  void update(int index, int val)
  {
    int size = fenTree.size();
    while (index < size)
    {
      fenTree[index] += val;
      index += index & (-index);
    }
  }

  int sum(int index)
  {
    int result = 0;
    while (index > 0)
    {
      result += fenTree[index];
      index -= index & (-index);
    }
    return result;
  }

  int rangeSum(int l, int r)
  {
    return sum(r) - sum(l - 1);
  }

  // check below fn
  int findLowerBound(int val)
  {
    int n = fenTree.size();
    int curr = 0, prevSum = 0;

    for (int i = log2(n); i >= 0; i--)
    {
      if (fenTree[curr + (1 << i)] + prevSum < val)
      {
        curr += (1 << i);
        prevSum += fenTree[curr];
      }
    }

    return curr + 1;
  }
};

int main()
{
  // Sample Test Case 1
  FenwickTree fenwick(10);
  fenwick.update(1, 10);
  fenwick.update(2, 20);
  fenwick.update(3, 30);
  cout << "Lower bound for 25: " << fenwick.findLowerBound(25) << endl; // Expected: 3

  // Sample Test Case 2
  FenwickTree fenwick2(5);
  fenwick2.update(1, 5);
  fenwick2.update(2, 15);
  fenwick2.update(4, 10);
  cout << "Lower bound for 20: " << fenwick2.findLowerBound(20) << endl; // Expected: 2

  // Additional Test Cases
  FenwickTree fenwick3(3);
  fenwick3.update(1, 5);
  fenwick3.update(2, 10);
  fenwick3.update(3, 15);
  cout << "Lower bound for 1: " << fenwick3.findLowerBound(1) << endl; // Expected: 1

  cout << "Lower bound for 50: " << fenwick3.findLowerBound(50) << endl; // Expected: 4

  FenwickTree fenwick4(5);
  cout << "Lower bound for 1 in zero-initialized tree: " << fenwick4.findLowerBound(1) << endl; // Expected: 6 or out-of-bounds value

  FenwickTree fenwick5(5);
  fenwick5.update(1, 100);
  fenwick5.update(2, 200);
  fenwick5.update(3, 300);
  fenwick5.update(4, 400);
  fenwick5.update(5, 500);
  cout << "Lower bound for 600: " << fenwick5.findLowerBound(600) << endl; // Expected: 4

  return 0;
}
