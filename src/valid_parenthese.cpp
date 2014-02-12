#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// compiler parser solution:
//
// parenthese expression grammar:
//   F -> empty | (F)F | [F]F | {F}F
// LL(1) 
class Solution {
 public:
  int cur; // look ahead pointer
  string s;

  bool isValid(string s) {
    this->s = s;
    cur = 0;
    return F() && cur >= s.size();
  }

  bool F() {
    // reach end.
    if (cur >= s.size())
      return true;
    // look ahead is right parenthesessis, match empty
    if (!is_left_parenthese(s[cur]))
      return true;
    // match (F)F | [F]F | {F}F 
    char prev_char = s[cur];
    ++cur;
    bool is_valid = F();
    if (cur >= s.size())
      return false;
    char cur_char = s[cur];
    ++cur;
    return is_valid && is_match_pair(prev_char, cur_char) && F(); 
  }

  bool is_match_pair(char a, char b) {
    return a == '(' && b == ')' || a == '[' && b == ']' || a == '{' && b == '}';
  }

  bool is_left_parenthese(char a) {
    return a == '(' || a == '{' || a == '[';
  }
};

class Solution2 {
 public:
  bool isValid(string s) {
    stack<string::value_type> st;
    int i = 0;
    for (; i < s.size(); ++i) {
      if (s[i] == '{' || s[i] == '(' || s[i] == '[')
        st.push(s[i]);
      else if (st.empty()) {
        break;
      } else if (is_match(st.top(), s[i])) {
        st.pop();
      } else
        break;
    } 
    return st.empty() && i == s.size();
  }
  bool is_match(char a, char b) {
    return a == '(' && b == ')' || a == '[' && b == ']' || a == '{' && b == '}';
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  string str[] = {"[", "[]()", "{[()]}()", "()()()(){}{}{}(())"};
  int size = 4;
  Solution s;
  for (int i = 0; i < size; ++i) {
    cout << s.isValid(str[i]) << endl;
  }
  return 0;
} 
