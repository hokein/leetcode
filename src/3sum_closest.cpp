#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// 3sum problem variation. 
class Solution {
 public:
  int dis(int a, int b) {
    return a > b? a-b:b-a;
  }
  int threeSumClosest(vector<int> &num, int target) {
    sort(num.begin(), num.end());
    int ans = 0;
    for (int i = 0; i < min((int)num.size(), 3); ++i)
      ans += num[i];
    for (int i = 0; i < num.size(); ++i) {
      int find_value = target - num[i];
      int st = i+1, ed = num.size() - 1;
      while (st < ed) {
        int sum = num[st] + num[ed] + num[i];
        if (num[st] + num[ed] == find_value) {
          return sum;
        } else if (num[st] + num[ed] > find_value) {
          if (dis(ans, target) > dis(sum, target))
            ans = sum;
          --ed;
        } else {
          if (dis(ans, target) > dis(sum, target))
            ans = sum;
          ++st;
        }
      }
    }
    return ans;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  vector<int> data;
  int a;
  while (scanf("%d,", &a) != EOF) {
    data.push_back(a);
  }
  cout << data.size() << endl;
  //for (int i = 0; i < data.size(); ++i)
    //cout << data[i] << " ";
  //cout << endl;
  Solution s;
  cout << s.threeSumClosest(data, 1) << endl;
  return 0;
} 

