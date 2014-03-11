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
  string addBinary(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    int i = 0, j = 0;
    int add_num = 0;
    string result;
    while (i < a.size() || j < b.size()) {
      if (i >= a.size()) {
        int sum = (b[j++]-'0'+add_num);
        result.push_back('0'+sum%2);
        add_num = sum/2;
      } else if (j >= b.size()){
        int sum = (a[i++]-'0'+add_num);
        result.push_back('0'+sum%2);
        add_num = sum/2;
      } else {
        int sum = (a[i++]-'0'+b[j++]-'0'+add_num);
        result.push_back('0'+sum%2);
        add_num = sum/2;
      }
    }    
    if (add_num)
      result.push_back(add_num+'0');
    return string(result.rbegin(), result.rend());
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  Solution s;
  cout << s.addBinary("11", "11") << endl;
  return 0;
} 
