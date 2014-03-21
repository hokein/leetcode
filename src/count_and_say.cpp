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
  string countAndSay(int n) {
    string ans = "1";
    while (--n) {
      int i = 0;
      string next;
      while (i < ans.size()) {
        int cnt = 1;
        int j = i+1;
        while (j < ans.size() && ans[j] == ans[j-1]) {
          ++cnt;
          ++j;
        }
        while (cnt) {
          next.push_back(cnt%10+'0');
          cnt /= 10;
        }
        next.push_back(ans[j-1]);
        i = j;
      }
      ans = next;
    }    
    return ans;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  Solution s;
  cout << s.countAndSay(1) << endl;
  cout << s.countAndSay(2) << endl;
  cout << s.countAndSay(3) << endl;
  cout << s.countAndSay(4) << endl;
  cout << s.countAndSay(5) << endl;
  cout << s.countAndSay(6) << endl;
  return 0;
} 
