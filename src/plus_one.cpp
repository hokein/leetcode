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
  vector<int> plusOne(vector<int> &digits) {
    vector<int> result;      
    int add_dig = 1;
    for (int i = digits.size()-1; i >= 0; --i) {
      result.push_back((digits[i]+add_dig)%10);
      add_dig = (digits[i]+add_dig)/10;
    }
    if (add_dig)
      result.push_back(add_dig);
    reverse(result.begin(), result.end());
    return result;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  vector<int> data;
  data.push_back(1);
  data.push_back(2);
  Solution s;
  vector<int> res = s.plusOne(data);
  for (int i = 0; i < res.size(); ++i)
    cout << res[i];
  cout << endl;
  return 0;
} 
