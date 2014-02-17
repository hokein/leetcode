#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// O(n) enum solution.
class Solution {
 public:
  int maxProfit(vector<int> &prices) {
    if (prices.size() < 2)
      return 0;
    vector<int> mini(prices.size());
    vector<int> maxx(prices.size());
    vector<int> right(prices.size());
    // prefix min num 
    // mini[i]: min{a[j], 0 <= j <= i}
    mini[0] = prices[0];
    for (int i = 1; i < prices.size(); ++i)
      mini[i] = min(prices[i], mini[i-1]);
    // postfix max num
    // maxx[i]: max{a[j], i <= j <= n}
    maxx[prices.size()-1] = prices.back();
    for (int i = prices.size()-2; i >= 0; --i)
      maxx[i] = max(prices[i], maxx[i+1]);
    // max profit
    // right[i]: max{maxx[j]-prices[j],  i <= j <= n}
    // right[i]: the max profit from a[i..n]
    right[prices.size()-1] = maxx[prices.size()-1]-prices.back();
    for (int i = prices.size()-2; i >= 0; --i)
      right[i] = max(right[i+1], maxx[i]-prices[i]);

    // [buy, sell], [buy sell]
    // [small, big], [small, big]
    //          |
    //         enum place
    // Enum the left start position.
    int ans = prices.back()-mini[prices.size()-1];
    for (int i = 0; i < prices.size()-1; ++i)
        ans = max(ans, prices[i]-mini[i]+right[i+1]);
    return ans;
  }
};

// A wrong solution using divide and conquer.
// Test case: 6,7,2,6,4,3,8,2,7,5
//class Solution2 {
 //public:
  //int ans;
  //vector<int> prices;  
  //int maxProfit(vector<int> &prices) {
    //if (prices.size() == 1 || prices.size() == 0)
      //return 0;
    //ans = 0;
    //this->prices = prices;
    //int left, right;
    //solve(0, this->prices.size()-1, &left, &right);
    //return ans;
  //}

  //bool is_decrease_sorted(int ll, int rr) {
    //for (int i = ll+1; i <= rr; ++i) {
      //if (prices[i-1] >= prices[i])
        //continue;
      //return false;
    //}
    //return true;
  //}

  //int solve(int ll, int rr, int *ret_l, int *ret_r) {
    //if (rr <= ll)
      //return -1;
    //if (rr-ll == 1) {
      //if (prices[rr]-prices[ll] > 0) {
        //*ret_l = ll;
        //*ret_r = rr;
        //ans = max(ans, prices[rr]-prices[ll]);
        //return prices[rr]-prices[ll];
      //} 
      //return -1;
    //}

    //int ret_ans = -1;
    //if (is_decrease_sorted(ll, rr))
      //return -1;
    //int mid = (rr+ll)/2;
    //int left_l, left_r, right_l, right_r;
    //int left = solve(ll, mid, &left_l, &left_r);
    //int right = solve(mid+1, rr, &right_l, &right_r);

    //int mini = prices[ll];
    //int mini_pos = ll;
    //for (int i = ll; i <= mid; ++i) {
      //if (mini > prices[i])
        //mini = prices[mini_pos=i];
    //}
    //int maxx = prices[mid+1];
    //int maxx_pos = mid+1;
    //for (int j = mid+1; j <= rr; ++j) {
      //if (maxx <= prices[j])
        //maxx = prices[maxx_pos=j];
    //}

    //ans = max(ans, maxx-mini);
    //ans = max(ans, max(left, right));
    //ans = max(ans, left+right);

    //if (left != -1) {
      //int mini_a = prices[left_r+1];
      //int mini_a_pos = left_r+1;
      //for (int i = mini_a_pos; i <= mid; ++i)
        //if (mini_a > prices[i])
          //mini_a = prices[mini_a_pos=i];
      //if (left_r < mid)
        //ans = max(ans, left+maxx-mini_a);
    //}
    //if (right != -1) {
      //int maxx_a = prices[mid+1];
      //int maxx_a_pos = mid+1;
      //for (int i = maxx_a_pos; i < right_l; ++i)
        //if (maxx_a < prices[i])
          //maxx_a = prices[maxx_a_pos=i];
      //if (right_l > mid+1) {
        //ans = max(ans, right+maxx_a-mini);
      //}
    //}

    //int internal_l, internal_r;
    //if (left > ret_ans) {
      //ret_ans = left;
      //*ret_l = left_l;
      //*ret_r = left_r;
    //}
    //if (right > ret_ans) {
      //ret_ans = right;
      //*ret_l = right_l;
      //*ret_r = right_r;
    //} 
    //if (maxx-mini > 0 && maxx-mini > ret_ans) {
      //ret_ans = maxx-mini;
      //*ret_l = mini_pos;
      //*ret_r = maxx_pos;
    //}
    //return ret_ans;
  //} 
//};

int main() {
  freopen("test.txt", "r", stdin);

  //int data[] = {6,7,2,6,4,3,8,2,7,5};
  int data[] = {3,2,6,5,0,3}; 
  vector<int> v(data, data+sizeof(data)/sizeof(int));
  Solution s;
  cout << s.maxProfit(v) << endl;
  return 0;
} 
