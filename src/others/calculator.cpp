#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// A simple expression calculator using LL(1) analysis:
//   supports +, -, *, /, and ()
//   without error detection.
//
// EBNF:
//   expr -> expr ADD term | term
//   term -> term MUL factor | factor
//   factor -> number | (expr) | neg factor 
//   neg -> + / -
//   ADD -> + / -
//   MUL -> * / /
//
// we can find it's left recursive, we can't use it in recursive programming
// it will cause infinite loop.
// In programming, we use iteration instead.
string s;
int cur;

string get_token() {
  if (!(s[cur] >= '0' && s[cur] <= '9'))
    return string(1, s[cur++]);

  string token = "";
  while (s[cur] >= '0' && s[cur] <= '9') {
    token += s[cur++];
  }
  return token;
}

int str2num(const string& s) {
  int ret = 0;
  for (int i = 0; i < s.size(); ++i)
    ret = 10*ret + (s[i]-'0');
  return ret;
}

int expr();

int factor() {
  string token = get_token();
  if (token == "(") {
    int ret = expr();
    ++cur; // skip ')'
    return ret;
  } else if (token == "+") {
    return factor();
  } else if (token == "-") {
    return -factor();
  } else {
    return str2num(token);
  }
}

int term() {
  int op1 = factor();
  if (cur > s.size())
    return op1;
  char cur_char = s[cur];
  // iteration
  while (cur_char == '*' || cur_char == '/') {
    ++cur;
    int op2 = factor();
    if (cur_char == '*')
      op1 *= op2;
    else if (cur_char == '/')
      op1 /= op2;
    cur_char = s[cur];
  }
  return op1;
}

int expr() {
  int op1 = term();
  if (cur > s.size())
    return op1;
  char cur_char = s[cur];
  // iteraion.
  while (cur_char == '+' || cur_char == '-') {
    ++cur;
    int op2 = term();
    if (cur_char == '+')
      op1 += op2;
    else if (cur_char == '-')
      op1 -= op2;
    cur_char = s[cur];
  }
  return op1;
}

int main() {
  string test_cases[] = {
    "8/4/2",
    "8/(4/-2)",
    "(1)",
    "(2+3)",
    "3-2---1",
    "8/(4/--2)",
  };
  int sizes = 6;
  for (int i = 0; i < sizes; ++i) {
    s = test_cases[i];
    cur = 0;
    cout << expr() << endl;
  }
  return 0;
} 
