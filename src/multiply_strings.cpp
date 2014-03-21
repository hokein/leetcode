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
  string multiply(string num1, string num2) {
    string result = "";
    for (int i = 0; i < num2.size(); ++i) {
      if (result != "0")
        result.push_back('0');
      result = add(result, multiple(num1, num2[i]-'0'));
    }  
    return result;
  }

  string add(const string& s1, const string& s2) {
    string ans;
    int add_num = 0;
    int i = s1.size()-1;
    int j = s2.size()-1;
    for (; i >= 0 && j >= 0;) { 
      int new_val = s1[i--]-'0' + s2[j--]-'0' + add_num;
      ans.push_back(new_val%10 + '0');
      add_num = new_val/10;
    }
    while (i >= 0) {
      int new_val = s1[i--]-'0' + add_num;
      ans.push_back(new_val%10 + '0');
      add_num = new_val/10;
    }
    while (j >= 0) {
      int new_val = s2[j--]-'0' + add_num;
      ans.push_back(new_val%10 + '0');
      add_num = new_val/10;
    }
    if (add_num)
      ans.push_back(add_num+'0');
    reverse(ans.begin(), ans.end());
    return ans;
  }

  string multiple(const string& num, int val) {
    string ans;
    int add = 0;
    for (int i = num.size()-1; i >= 0; --i) {
      int new_val = (num[i]-'0')*val + add;
      ans.push_back(new_val%10 + '0');
      add = new_val/10;
    }
    if (add)
      ans.push_back(add+'0');
    reverse(ans.begin(), ans.end());
    int pos = 0;
    while (pos < ans.size() && ans[pos] == '0')
      ++pos;
    return pos >= ans.size()? "0" : ans;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  Solution s;
  cout << s.multiply("0", "999999") << endl;
  cout << s.multiply("999999", "0") << endl;
  return 0;
} 
