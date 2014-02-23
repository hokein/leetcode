#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

 //Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
 public:
  vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> result;
    for (int i = 0; i < intervals.size(); ++i) {
      if (newInterval.end < intervals[i].start) {
        result.push_back(newInterval);
        while (i < intervals.size()) 
          result.push_back(intervals[i++]);
        return result;
      } else if (newInterval.start > intervals[i].end) {
        result.push_back(intervals[i]);
      } else {
        newInterval.start = min(newInterval.start, intervals[i].start);
        newInterval.end = max(newInterval.end, intervals[i].end);
      }
    }
    result.push_back(newInterval);
    return result;
  }
};

class Solution2 {
 public:
  vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> result;
    if (intervals.size() == 0) return vector<Interval>(1, newInterval);
    if (newInterval.end < (intervals.begin())->start) { // first one
      result = intervals;
      result.insert(result.begin(), newInterval);
      return result;
    }
    if (newInterval.start > (intervals.back()).end) { // last one
      result = intervals;
      result.push_back(newInterval);
      return result;
    }
    for (int i = 0; i < intervals.size(); ) {
      if (!is_overlap(intervals[i], newInterval)) {
        result.push_back(intervals[i]);
        // a special case need to be considered.
        // [1, 3] [6, 7], insert [5, 5].
        if (i+1 < intervals.size() && intervals[i].end < newInterval.start
            && intervals[i+1].start > newInterval.end)
          result.push_back(newInterval);
        ++i; 
        continue;
      }
      int j = i;
      int new_start = min(intervals[j].start, newInterval.start);
      int new_end = newInterval.end;
      while (j < intervals.size() && is_overlap(newInterval, intervals[j])) {
        new_end = max(intervals[j].end, new_end);
        ++j;
      }
      result.push_back(Interval(new_start, new_end));
      i = j; 
    }    
    return result;
  }

  bool is_overlap(Interval a, Interval b) {
    return !(a.end < b.start || b.end < a.start);
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  vector<Interval> intervals;
  intervals.push_back(Interval(1,2));
  intervals.push_back(Interval(4,5));
  intervals.push_back(Interval(6,7));
  intervals.push_back(Interval(8, 10));
  intervals.push_back(Interval(12, 16));
  Solution s;
  
  vector<Interval> ans = s.insert(intervals, Interval(3, 3));
  for (int i = 0; i < ans.size(); ++i)
    cout << ans[i].start << " " << ans[i].end << endl;
  return 0;
} 
