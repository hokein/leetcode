#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

bool cmp(const Interval& a, const Interval& b) {
  if (a.start != b.start)
    return a.start < b.start;
  return a.end < b.end;
}

class Solution {
 public:
  vector<Interval> merge(vector<Interval> &intervals) {
    vector<Interval> result;
    sort(intervals.begin(), intervals.end(), cmp);
    for (int i = 0; i < intervals.size(); ++i) {
      if (result.size() == 0 || intervals[i].start > result.back().end)
        result.push_back(intervals[i]);
      else {
        if (result.back().end >= intervals[i].start)
          result.back().end = max(result.back().end, intervals[i].end);
      }
    }
    return result;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  vector<Interval> intervals;
  intervals.push_back(Interval(1,2));
  intervals.push_back(Interval(0,3));
  //intervals.push_back(Interval(6, 9));
  //intervals.push_back(Interval(8, 10));
  Solution s;
  
  vector<Interval> ans = s.merge(intervals);
  for (int i = 0; i < ans.size(); ++i)
    cout << ans[i].start << " " << ans[i].end << endl;
  return 0;
} 
