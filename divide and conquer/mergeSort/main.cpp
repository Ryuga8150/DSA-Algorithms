#include <bits/stdc++.h>
using namespace std;

// T.C:- O(N logN)
// S.C:- O(N)

void merge(int low, int mid, int high, vector<int> &arr)
{
  vector<int> temp;

  int i = low;
  int j = mid + 1;

  while (i <= mid && j <= high){

    if (arr[i] <= arr[j]){
      temp.push_back(arr[i]);
      i++;
    }
  
    else{
      temp.push_back(arr[j]);
      j++;
    }

  }

  while (i <= mid){
    temp.push_back(arr[i]);
    i++;
  }
  
  while (j <= high){
    temp.push_back(arr[j]);
    j++;
  }


  for(int k = low; k <= high; ++k){
    arr[k]=temp[k-low];
  }

}
void mergeSort(int low, int high, vector<int> &arr){
  // imp condition equal to
  if (low >= high){
    return;
  }

  int mid = low + (high - low) / 2;

  mergeSort(low, mid, arr);
  mergeSort(mid + 1, high, arr);

  merge(low, mid, high, arr);
}

void displayArr(vector<int>& arr){
  for(int i=0;i<arr.size();++i){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

int main()
{
  vector<int> arr{2, 5, 4, 7,-1};
  int low = 0;
  int high = arr.size() - 1;

  mergeSort(low, high, arr);

  displayArr(arr);
  return 0;
}