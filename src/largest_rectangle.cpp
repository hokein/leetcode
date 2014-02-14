#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// Find the larget rectangle area.
// Solution: stack.
//
// 1. Use a stack maintain a increasing sequence.
// 2. Iterative height array, height[i]:
//    * st.top <= height[i], push into stack.  
//    * else pop stack element until st.top < height[i], update the maximum value.
class Solution {
 public:
  int largestRectangleArea(vector<int> &height) {
    stack<int> st;
    int maximum = 0;
    for (int i = 0; i < height.size(); ++i) {
      if (st.empty() || height[st.top()] <= height[i])
        st.push(i);
      else {
        while (!st.empty() && height[st.top()] > height[i]) {
          int cur = st.top();
          st.pop();
          if (st.empty())
            maximum = max(maximum, height[cur]*i);
          else
            maximum = max(maximum, height[cur]*(i-st.top()-1));
        }
        st.push(i);
      }
    }
    while (!st.empty()) {
      int cur = st.top();
      st.pop();
      if (st.empty())
        maximum = max(maximum, (int)(height[cur]*height.size()));
      else
        maximum = max(maximum, height[cur]*(int)(height.size()-st.top()-1));
    }
    return maximum;
  }
};

class Solution2 {
 public:
  int largestRectangleArea(vector<int> &height) {
    stack<int> st;
    int maximum = 0;
    for (int i = 0; i < height.size(); ++i) {
      if (st.empty() || height[i] >= st.top()) {
        st.push(height[i]);
      } else {
        int cnt = 0;
        while (!st.empty() && st.top() > height[i]) {
          ++cnt;
          // st.top() is the minimal height
          maximum = max(maximum, st.top()*cnt);
          st.pop();
        }
        st.push(height[i]);
        // replace the bigger element with smaller element(height[i])
        while (cnt--) {
          st.push(height[i]);
        }
      } 
    } 
    int cnt = 0;
    while (!st.empty()) {
      ++cnt;
      maximum = max(maximum, st.top()*cnt);
      st.pop();
    }
    return maximum;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  //int a[] = {4,2,0,3,2,4,3,4};
  int a[] = {5,4,1,2};
  vector<int> data(a, a+4);
  Solution s;
  cout << s.largestRectangleArea(data) << endl;
  return 0;
} 
