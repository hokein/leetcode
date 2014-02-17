#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// Using a stack to hold a increase sequence.
class Solution {
 public:
  int maxProfit(vector<int> &prices) {
    vector<int> st;
    int sum = 0;
    for (int i = 0; i < prices.size(); ++i) {
      if (st.empty())
        st.push_back(prices[i]);
      else {
        if (st.back() < prices[i])
          st.push_back(prices[i]);
        else if (st.size() == 1) {
          st[0] = prices[i];
        } else {
          sum += st[st.size()-1]-st[0];
          st.clear();
          st.push_back(prices[i]);
        }
      }
    }    
    if (st.size() > 1) {
      sum += st[st.size()-1]-st[0];
    }
    return sum;
  }
};

int main() {
  freopen("test.txt", "r", stdin);


  int data[] = {3, 1, 0};
  vector<int> v(data, data+3);
  Solution s;
  cout << s.maxProfit(v) << endl;
  return 0;
} 
