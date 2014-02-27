#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// Determine a string is valid or not
//
// .1
// 1.
// 1.e10
// 10e-10
// +10e+10
// -10e-10
//
// Lexcial analysis, DFA.
class Solution {
 public:
  enum Token {
    OPERATOR, // +/-
    DIGIT, // 0~9
    DOT, // .
    E, // e
  }; 
  bool isNumber(const char *s) {
    int len = strlen(s);
    // skip the beginning/ending characters
    while (len-1 >= 0 && s[len-1] == ' ')
      --len;
    int i = 0;
    while (s[i] == ' ') {
      ++i;
    }
    // state transform table.
    int table[][4] = {
      1, 2, 3, -1,
      -1, 2, 3, -1,
      -1, 2, 4, 5,
      -1, 8, -1, -1,
      -1, 4, -1, 5,
      6, 7, -1, -1,
      -1, 7, -1, -1,
      -1, 7, -1, -1,
      -1, 8, -1, 5,
    };
    int state = 0;
    Token token; 
    for (; i < len && state != -1; ++i) {
      if (s[i] == '+' || s[i] == '-') 
        token = OPERATOR;
      else if (s[i] >= '0' && s[i] <= '9')
        token = DIGIT;
      else if (s[i] == '.')
        token = DOT;
      else if (s[i] == 'e')
        token = E;
      else {
        state = -1;
        break;
      }
      state = table[state][token];
    }
    return state == 2 || state == 4 || state == 7 || state == 8;
  }
};

class Solution2 {
 public:
  bool isNumber(const char *s) {
    int len = strlen(s);
    while (len-1 >= 0 && s[len-1] == ' ')
      --len;
    int i = 0;
    while (i < len && s[i] == ' ')      
      ++i;

    if (i < len && (s[i] == '+' || s[i] == '-'))
      ++i;

    if (i == len)
      return false;
    while (i < len && s[i] >= '0' && s[i] <= '9') {
      ++i;
    }
    if (i == len)
      return true;
    if (i < len && s[i] == '.') {
      if (i-1 >= 0 && s[i-1] >= '0' && s[i-1] <= '9'
          || i+1 < len && s[i+1] >= '0' && s[i+1] <= '9') {
        ++i;
        while (i < len && s[i] >= '0' && s[i] <= '9') {
          ++i;
        }
        if (i == len)
          return true;
      }
    }
    if (i < len && (s[i] == 'e' && i > 0 && (s[i-1] >= '0' && s[i-1] <= '9' || s[i-1] == '.'))) {
      ++i;
      while (i < len && (s[i] == '+' || s[i] == '-'))
        ++i;
      if (i == len)
        return false;
      while (i < len && s[i] >= '0' && s[i] <= '9') {
        ++i;
      }
      return i == len;
    }
    return false;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  char* data[] = {
    "",
    "0",
    "123",
    "12.3",
    "-12",
    "-11.1",
    "10e10 ",
    "10e-10",
    "-10e-10",
    ".2",
    "1  a",
    "  1  ",
    "e9",
    "3.",
    "46.e10",
    "1.e1",
    "e-e",
    "0. 1",
    ".1.",
  };

  Solution s;
  for (int i = 0; i < sizeof(data)/sizeof(char *); ++i)
    cout << data[i] << ": " << s.isNumber(data[i]) << endl;
  return 0;
} 
