#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

class Solution {
 public:
  int str2num(const string& s) {
    int i = 0;
    int is_negative = false;
    while (i < s.size() && s[i] == '-') {
      is_negative = !is_negative;
      ++i;
    }
    int result = 0;
    for (;i < s.size(); ++i)
      result = 10*result + s[i]-'0';
    return is_negative?-result:result; 
  } 
  int evalRPN(vector<string> &tokens) {
    stack<int> st;
    for (int i = 0; i < tokens.size(); ++i) {
      if (tokens[i] == "+" || tokens[i] == "-" ||
          tokens[i] == "*" || tokens[i] == "/") {
        int op1 = st.top();
        st.pop();
        int op2 = st.top();
        st.pop();
        if (tokens[i] == "+")
          st.push(op1+op2);
        else if (tokens[i] == "*")
          st.push(op1*op2);
        else if (tokens[i] == "-")
          st.push(op2-op1);
        else 
          st.push(op2/op1);
      } else  {
        st.push(str2num(tokens[i]));
      } 
    }   
    return st.top();
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  string data[] = {"2", "1", "+", "-3", "*"};
  vector<string> ss(data, data+5);
  Solution s;
  cout << s.evalRPN(ss) << endl;
  return 0;
} 
