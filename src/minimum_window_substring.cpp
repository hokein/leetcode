#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// Two Pointer Scan: O(n)
class Solution {
public:
  string minWindow(string S, string T) {
    const int N = 300;
    const int INF = 100000000;
    vector<int> cnts(N, 0);
    vector<int> cur_cnts(N, 0);
    for (int i = 0; i < T.size(); ++i)   
      ++cnts[T[i]];

    int st = 0;
    int appeared = 0;
    int mini = INF;
    int mini_st = 0;
    // Two pointers, st, ed
    for (int ed = 0; ed < S.size(); ++ed) {
      if (cnts[S[ed]] > 0) {
        ++cur_cnts[S[ed]];
        if (cur_cnts[S[ed]] <= cnts[S[ed]])
          ++appeared;
      }
      if (appeared == T.size()) {
        // reduce st pointer
        while (st <= ed && (cur_cnts[S[st]] > cnts[S[st]] || cnts[S[st]] == 0)) {
          --cur_cnts[S[st]];
          ++st;
        }
        if (mini > ed-st+1) {
          mini = ed-st+1;
          mini_st = st;
        }  
      }
    }
    if (mini == INF)
      return "";
    return S.substr(mini_st, mini);
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  Solution s;
  cout << s.minWindow("bdab", "ab") << endl;
  return 0;
} 
