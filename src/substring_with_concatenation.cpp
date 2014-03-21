#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// Find concatenation of all words in S.
//
// O(n*m)
//  
class Solution {
 public:
  vector<int> findSubstring(string S, vector<string> &L) {
    int word_len = L.front().size();
    int len = word_len*L.size();
    vector<int> ans;
    map<string, int> mp;
    if (S.size() < len)
      return ans;
    for (int i = 0; i < L.size(); ++i)
      ++mp[L[i]];

    for (int i = 0; i+len <= S.size(); ++i) { // enum start position.
      map<string, int> cnts = mp;
      for (int j = i; j < i+len; j += word_len) { // check [i, i+len)
        string word(S, j, word_len);
        map<string, int>::iterator it = cnts.find(word);
        if (it == cnts.end())
          break;
        --(it->second);
        if (it->second == 0)
          cnts.erase(it);
      }
      if (cnts.empty())
        ans.push_back(i);
    }
    return ans;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  vector<string> v;
  v.push_back("foo");
  v.push_back("bar");
  Solution s;
  vector<int> ans = s.findSubstring("barfoothefoobarman", v);
  for (int i = 0; i < ans.size(); ++i)
    cout << ans[i] << endl;
  return 0;
} 
