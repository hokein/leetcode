#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// Next permutation implementation:
//
// 1. find the first pair, a[i-1] < a[i] from end.
// 2. find a[j] > a[i-1] from end and swap(a[j], a[i-1]).
// 3. reverse(a[i], ... a[n-1]).
class Solution {
public:
  void nextPermutation(vector<int> &num) {
    int ii = num.size()-1;
    for (; ii > 0; --ii) {
      if (num[ii-1] < num[ii])
        break;
    }    
    if (ii == 0) 
      reverse(num.begin(), num.end());
    else {
      for (int j = num.size()-1; j >= 0; --j)
        if (num[j] > num[ii-1]) {
          swap(num[j], num[ii-1]);
          reverse(num.begin()+ii, num.end());
          break;
        }
    }
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  vector<int> num;
  num.push_back(3);
  num.push_back(2);
  num.push_back(1);
  Solution s;
  s.nextPermutation(num);
  for (int i = 0; i < num.size(); ++i)
    cout << num[i] << " ";
  cout << endl;
  return 0;
} 
