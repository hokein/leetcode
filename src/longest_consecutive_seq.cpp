#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// Given a unsorted array, find longest consecutive sequence in O(n)
//
class Solution {
 public:
  int longestConsecutive(vector<int> &num) {
    // hash set, insert and remove is O(1)
    unordered_set<int> s;
    for (int i = 0; i < num.size(); ++i)
      s.insert(num[i]);
    int ans = 0;
    for (int i = 0; i < num.size(); ++i) {
      if (s.find(num[i]) != s.end()) {
        s.erase(num[i]);
        int left = 0;
        // find left parts.
        for (int j = num[i]-1; s.find(j) != s.end(); --j) {
          ++left;
          s.erase(j);
        }
        int right = 0;
        // find right parts.
        for (int j = num[i]+1; s.find(j) != s.end(); ++j) {
          ++right;
          s.erase(j);
        }
        ans = max(left+right+1, ans);
      }
    }
    return ans;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  int data[] = {3, 5, 0, -1};
  int len = sizeof(data)/sizeof(int);
  vector<int> v(data, data+len);
  Solution s;
  cout << s.longestConsecutive(v) << endl;
  return 0;
} 
