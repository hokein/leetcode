#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// O(n) with O(n) space.
//
// Step1: find out all matched position.
// Step2: find the longest continues 1s sequences. 
class Solution {
 public:
  int longestValidParentheses(string s) {
    if (s.empty())
      return 0;
    vector<bool> vis(s.size(), 0);
    vector<int> sum(s.size(), 0);
    vector<int> st;
    // Fill vis array, matched position marks 1.
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(') {
        st.push_back(i);
      } else {
        if (st.empty())
          continue;
        int top = st.back();
        st.pop_back();
        vis[i] = 1;
        vis[top] = 1;
      }   
    }

    // find the longest continues 1s sequences using DP. 
    sum[0] = vis[0];
    int ans = 0;
    for (int i = 1; i < s.size(); ++i) {
      if (!vis[i])
        sum[i] = 0;
      else { 
        sum[i] = max(sum[i-1]+1, 1);
        ans = max(sum[i], ans);
      }
    }
    return ans;
  }
};

// A more simpler solution with O(n) complexity an O(n) space
class Solution2 {
 public:
  int longestValidParentheses(string s) {
    int ans = 0;
    int last = -1;
    vector<int> st;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(')
        st.push_back(i);
      else {
        if (st.empty()) {
          last = i; // record last invalid ')' position.
        } else {
          st.pop_back();
          if (st.empty())
            ans = max(ans, i-last);
          else
            ans = max(ans, i-st.back());
        }
      }
    }
    return ans;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  string ss = ")()())()()(";
  //string ss = ""; 
  Solution s;
  cout << s.longestValidParentheses(ss) << endl;
  return 0;
} 
