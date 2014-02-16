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
  vector<vector<char> > tables;
  vector<string> result;
  string num;
  string seq;
  vector<string> letterCombinations(string digits) {
    char c = 'a';
    num = digits;
    tables = vector<vector<char> >(10);
    tables[0].push_back(' ');
    for (int i = 2; i < 10; ++i) {
      for (int j = 0; j < 3; ++j)
        tables[i].push_back(c++);
      if (i == 7 || i == 9)
        tables[i].push_back(c++);
    }
    dfs(0);
    return result;
  }
  void dfs(int cur) {
    if (cur >= num.size()) {
      result.push_back(seq);
      return;
    }
    int pos = num[cur]-'0';
    for (int i = 0; i < tables[pos].size(); ++i) {
      seq.push_back(tables[pos][i]);
      dfs(cur+1);
      seq.erase(seq.end()-1);
      //seq.pop_back();
    }
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  Solution s;
  vector<string> result = s.letterCombinations("23");
  for (int i = 0; i < result.size(); ++i)
    cout << result[i] << endl; 
  return 0;
} 
