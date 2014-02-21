#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// Greedy
//          q p x r j x k
// first    |         |
// second         |        
//                j
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    vector<int> last_pos(max('A','a')+30, -1);
    int ans = 0, last_cnt = 0;
    int j = 0; // last index start postion
    for (int i = 0; i < s.size(); ++i) {
      if (last_pos[s[i]] == -1) { // unvised character.
        last_pos[s[i]] = i;
        ans = max(ans, ++last_cnt);
      } else {
        ans = max(ans, i-last_pos[s[i]]);
        last_cnt = i-last_pos[s[i]];
        // reset [j, index[s[i]]], mark -1
        for (int k = j; k < last_pos[s[i]]; ++k)
          last_pos[s[k]] = -1;
        j = last_pos[s[i]]+1;
        last_pos[s[i]] = i;
      }
    }
    return ans;
  }
};

// A more simplier solution.
class Solution2 {
 public:
  int lengthOfLongestSubstring(string s) {
    vector<int> last_pos(max('A','a')+30, -1);
    int ans = 0;
    int j = 0; // last index start postion
    for (int i = 0; i < s.size(); ++i) {
      if (last_pos[s[i]] > j) {
        ans = max(ans, last_pos[s[i]]-j);
        j = last_pos[s[i]] + 1;
      }
      last_pos[s[i]] = i;
    }
    return max(ans, (int)s.size()-j);
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  Solution s;
  cout << s.lengthOfLongestSubstring("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco") << endl;
  return 0;
} 
