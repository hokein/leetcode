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
  vector<string> result;
  vector<int> nums;
  string s;
  vector<string> restoreIpAddresses(string s) {
    this->s = s;  
    dfs(0);
    return result;
  }

  string int2str(int a) {
    string ret = "";
    do {
      ret = string(1, '0'+a%10) + ret;
      a /= 10;
    } while (a);
    return ret;
  }

  void dfs(int pos) {
    if (nums.size() == 4) {
      if (pos != s.size())
        return;
      string ip;
      for (int i = 0; i < nums.size(); ++i) {
        ip += int2str(nums[i]) + ".";
      }
      ip.erase(ip.end()-1); 
      result.push_back(ip);
      return;
    }

    int num = 0;
    for (int i = pos; i < pos+3; ++i) {
      num = 10*num + s[i] - '0';
      if (num > 255) break;
      nums.push_back(num);
      dfs(i+1);
      nums.pop_back();
      // only allow single 0.
      if (num == 0)
        break;
    }
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  Solution s;
  vector<string> ret = s.restoreIpAddresses("010010");
  for (int i = 0; i < ret.size(); ++i)
    cout << ret[i] << endl;
  return 0;
} 
