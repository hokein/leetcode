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
  bool isPalindrome(string s) {
    string clean_s; 
    for (int i = 0; i < s.size(); ++i)
      if (s[i] >= 'a' && s[i] <= 'z')
        clean_s.push_back(s[i]);
      else if(s[i] >= 'A' && s[i] <= 'Z')
        clean_s.push_back(s[i]-('A'-'a'));
      else if (s[i] >= '0' && s[i] <= '9')
        clean_s.push_back(s[i]);
    string revered_s = clean_s;
    reverse(revered_s.begin(), revered_s.end());
    return revered_s == clean_s;    
  }
};

int main() {
  freopen("test.txt", "r", stdin);
  Solution s;
  cout << s.isPalindrome("1Aa2") << endl;
  return 0;
} 
