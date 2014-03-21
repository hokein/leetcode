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
  vector<string> fullJustify(vector<string> &words, int L) {
    vector<string> result;   
    int i = 0;
    while (i < words.size()) {
      int cnt = 1;
      string line;
      int len = words[i].size();
      int j = i+1;
      int sum = 2;
      while (j < words.size() && len+words[j].size()+cnt <= L) {
        len += words[j++].size();
        ++cnt;
      } 
      line = words[i];
      if (cnt == 1)
        line += string(L-len, ' ');
      else {
        if (j == words.size()) {
          int extra_places = L-len;
          for (int k = 1; k < cnt; ++k) {
            line.push_back(' ');
            line += words[i+k];
            --extra_places;
          }
          line += string(extra_places, ' ');
        } else {
          int extra_places = L - len;
          int blanks = extra_places/(cnt-1);
          int remain = extra_places%(cnt-1);
          for (int k = 1; k < cnt; ++k) {
            line += string(blanks, ' ');
            if (blanks%2 == 0 && k == 1)
              line += string(remain, ' ');
            else if (blanks%2 == 1 && remain > 0) {
              line.push_back(' ');
              --remain;    
            }
            line += words[i+k];
          }
        }
      }
      result.push_back(line);
      i = j;
    }
    return result;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  vector<string> v;
  v.push_back("world");
  v.push_back("owes");
  v.push_back("you");
  v.push_back("a");
  v.push_back("living;");
  v.push_back("the");
  v.push_back("What");
  v.push_back("must");
  v.push_back("be");
  v.push_back("shall");
  v.push_back("be.");
  Solution s;
  vector<string> ans = s.fullJustify(v, 30);
  for (int i = 0; i < ans.size(); ++i)
    cout << ans[i] << endl;
  return 0;
} 
