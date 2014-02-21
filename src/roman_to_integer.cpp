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
  int romanToInt(string s) {
    map<char, int> roman2int;
    roman2int['M'] = 1000;
    roman2int['D'] = 500;
    roman2int['C'] = 100;
    roman2int['L'] = 50;
    roman2int['X'] = 10;
    roman2int['V'] = 5;
    roman2int['I'] = 1;
    int sum = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (i + 1 < s.size()) {
        if (roman2int[s[i]] < roman2int[s[i+1]]) {
          sum += roman2int[s[i+1]] - roman2int[s[i]];
          i += 1;
        } else {
          sum += roman2int[s[i]];
        }
      } else {
        sum += roman2int[s[i]];
      }
    }
    return sum;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  Solution s;
  cout << s.romanToInt("IV") << endl;
  return 0;
} 
