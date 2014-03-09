#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// O(n) scan solution
// left_max[i]: the maximum element between [0,...,i]
// right_max[i]: the maximum element between [i+1,...,n]
class Solution {
 public:
  int trap(int A[], int n) {
    if (n == 0)
      return 0;
    vector<int> left_max(n), right_max(n);
    left_max[0] = A[0];
    right_max[n-1-0] = A[n-1];
    for (int i = 1; i < n-1; ++i) {
      left_max[i] = max(left_max[i-1], A[i]);
      right_max[n-1-i] = max(right_max[n-1-i+1], A[n-1-i]);
    }
    int ans = 0;
    for (int i = 1; i < n-1; ++i)
      ans += max(min(left_max[i], right_max[i])-A[i], 0);
    return ans;
  }
};

// stack solution. O(n) space.
// A stack maintains all smaller elements.
// When meet a larger element, pop all the stack elements until s.top > A[i].
// Sum the difference between s.top-pop_data[i], and enlarge the pop_data top
// s.top and push back to the stack.
class Solution2 {
 public:
  int trap(int A[], int n) {
    stack<int> s;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (s.empty() || s.top() >= A[i])
        s.push(A[i]);
      else {
        vector<int> pop_data;
        while (!s.empty() && s.top() < A[i]) {
          pop_data.push_back(s.top());
          s.pop();
        }
        if (s.empty()) {
          for (int j = 0; j < pop_data.size()-1; ++j)
            ans += pop_data.back()-pop_data[j];
        } else {
          for (int j = 0; j < pop_data.size(); ++j) {
            ans += A[i]-pop_data[j];
            s.push(A[i]);
          }
        }
        s.push(A[i]);
      }
    }    
    return ans;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  int data[] = {0,1,0,2,1,0,1,3,2,1,2,1};
  Solution s;
  cout << s.trap(data, sizeof(data)/sizeof(int)) << endl;
  return 0;
} 
