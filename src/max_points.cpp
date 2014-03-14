#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// Definition for a point.
struct Point {
  int x;
  int y;
  Point() : x(0), y(0) {}
  Point(int a, int b) : x(a), y(b) {}
};

// Find maximum points on the same line.
class Solution {
 public:
  int maxPoints(vector<Point> &points) {
    if (points.size() <= 2)
      return points.size();
    int ans = 0;
    for (int i = 0; i < points.size(); ++i) 
      for (int j = i+1; j < points.size(); ++j) {
        int sum = 0;
        // case: equal points
        if (points[i].x == points[j].x && points[i].y == points[j].y) {
          for (int k = 0; k < points.size(); ++k) {
            if (points[i].x == points[k].x
                && points[i].y == points[k].y)
              ++sum;
          }
        } else { // case: not eaual points.
          for (int k = 0; k < points.size(); ++k) {
            // on the same line
            if (equal(points[i], points[j], points[k]))
              ++sum;
          }
        }
        ans = max(sum, ans);
      } 
    return ans;
  }
  bool equal(const Point& p1, const Point& p2, const Point& p3) {
    return (p3.y-p1.y)*(p2.x-p3.x) == (p2.y-p3.y)*(p3.x-p1.x);
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  Solution2 s;
  vector<Point> v;
  //v.push_back(Point(0, 0));
  //v.push_back(Point(0, 0));
  v.push_back(Point(1, 0));
  v.push_back(Point(1, 0));
  v.push_back(Point(1, 0));
  //v.push_back(Point(2, 0));
  //v.push_back(Point(100, 1));
  //
  //v.push_back(Point(84, 250));
  //v.push_back(Point(0, 0));
  //v.push_back(Point(1, 0));
  //v.push_back(Point(0, -70));
  //v.push_back(Point(0, -70));
  //v.push_back(Point(1, -1));
  //v.push_back(Point(21, 10));
  //v.push_back(Point(42, 90));
  //v.push_back(Point(-42, -230));
  cout << s.maxPoints(v) << endl;
  return 0;
} 
