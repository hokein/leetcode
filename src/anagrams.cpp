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

class Solution {
public:
  vector<string> anagrams(vector<string> &strs) {
    map<string, vector<int> > words;
    vector<string> result;
    for (int i = 0; i < strs.size(); ++i) {
      string word = strs[i];
      sort(word.begin(), word.end());
      words[word].push_back(i);
    }
    for (map<string, vector<int> >::iterator it = words.begin();
         it != words.end(); ++it) {
      if ((it->second).size() >= 2) {
        for (int i = 0; i < (it->second).size(); ++i)
          result.push_back(strs[(it->second)[i]]);
      }
    }
    return result;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  vector<string> data;
  data.push_back("cat");
  data.push_back("act");
  data.push_back("cta");
  data.push_back("c");
  Solution s;
  vector<string> ans = s.anagrams(data);
  for (int i = 0; i < ans.size(); ++i)
    cout << ans[i] << endl;
  return 0;
} 
