#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// find patterns 
// 
// *  *  *
// * ** **
// ** ** *
// *  *  *
// Find each row elements, 
// skip 2(nRows-1) elements, there is an element between them, except the first and last line.
class Solution {
public:
  string convert(string s, int nRows) {
    if (nRows == 1)
      return s;
    string ans;
    for (int i = 0; i < nRows; ++i) {
      int pos = i;
      while (pos < s.size()) {
        ans.push_back(s[pos]);
        pos += 2*(nRows-1);
        if (i != 0 && i != nRows-1 && pos-2*(i-1)-2 < s.size())
          ans.push_back(s[pos-2*(i-1)-2]);
      }
    }
    return ans;
  }
};

// Use 2-D matrix simulation: TLE
class Solution2 {
public:
  string convert(string s, int nRows) {
    if (nRows == 1)
      return s;
    vector<vector<char> > maze(nRows+1, vector<char>(s.size(), '.'));

    int ii = 0, jj = 0;
    for (int i = 0; i < s.size(); ++i) {
      maze[ii][jj] = s[i];
      if (jj%(nRows-1) == 0) {
        if (ii == nRows-1) {
          ++jj;
          --ii;
        } else {
          ++ii;
        }
      } else {
        ++jj;
        --ii;
      }
    }    

    string ans;
    for (int i = 0; i < maze.size(); ++i)
      for (int j = 0; j < maze[i].size(); ++j)
        if (maze[i][j] != '.')
          ans.push_back(maze[i][j]);
    return ans;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  Solution s;
  cout << s.convert("PAYPALISHIRING", 3) << endl;
  return 0;
} 
