#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

class Solution {
public:
  bool searchMatrix(vector<vector<int> > &matrix, int target) {
    int l = 0, r = matrix.size()*matrix[0].size()-1;
    int n = matrix.size();
    int m = matrix[0].size();
    while (l <= r) {
      int mid = l+(r-l)/2;
      if (matrix[mid/m][mid%m] == target)
        return true;
      else if (matrix[mid/m][mid%m] < target)
        l = mid+1;
      else
        r = mid-1;
    }
    return false;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  int data[] = {0, 1, 1, 2};
  int size = sizeof(data)/sizeof(int);
  vector<int> v1(data, data+size);
  int data2[] = {2, 3, 4, 5};
  vector<int> v2(data2, data2+size);
  vector<vector<int> > v;
  v.push_back(v1);
  v.push_back(v2);
  Solution s;
  cout << s.searchMatrix(v, 3);
  return 0;
} 
