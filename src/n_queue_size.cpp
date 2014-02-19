#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// A bitwise solution.
class Solution {
public:
  int ans;
  int totalNQueens(int n) {
    ans = 0;
    dfs(0, 0, 0, (1<<n)-1);
    return ans;
  }
  // ld: left dialog
  // rd: right_dialog, 0 means not occupy, 1 means occupied.
  // cols: column
  // all: the destination.
  void dfs(int ld, int cols, int rd, int all) {
    if (cols == all) { // reach the destination.
      ++ans;
      return;
    }
    // get all possible places.
    int possible_places = (~(ld|cols|rd)) & all;
    while (possible_places) {
      // Get one possible places.
      int bit = possible_places & (-possible_places);
      // remove the possible place.
      possible_places -= bit;
      dfs((ld|bit)<<1, cols|bit, (rd|bit)>>1, all);
    }
  }
};

// Classical DFS method.
// Brute force
// How to check left and right dialog.
//
// On the same left dialog, i-j is the same.
// On the same right dialog, i+j is the same. 
//
// For instance: 
//    1  2  3  4
// 1
// 2
// 3
// 4
//
class Solution2 {
public:
  const static int N = 20;
  char maze[N][N];
  bool vis_row[N], vis_col[N];
  bool left_dialog[2*N], right_dialog[2*N];
  int n, ans;
  int totalNQueens(int n) {
    this->n = n;
    ans = 0;
    memset(vis_row, 0, sizeof(vis_row));
    memset(vis_col, 0, sizeof(vis_col));
    memset(left_dialog, 0, sizeof(left_dialog));
    memset(right_dialog, 0, sizeof(right_dialog));
    memset(maze, '.', sizeof(maze));
    dfs(0, 0, 0);
    return ans;
  }
  bool check_dialog(int ii, int jj) {
    return !left_dialog[ii-jj+n] && !right_dialog[ii+jj];
  }
  void dfs(int cnt, int ii, int jj) {
    if (cnt == n) {
      ++ans;
      return;
    }
    for (int i = ii; i < n; ++i)
      for (int j = (i==ii?jj:0); j < n; ++j) {
        if (!vis_row[i] && !vis_col[j]) {
          if (!check_dialog(i, j))
            continue;
          vis_row[i] = vis_col[j] = left_dialog[i-j+n] = right_dialog[i+j] = 1;
          maze[i][j] = 'Q';
          dfs(cnt+1, i, j);
          vis_row[i] = vis_col[j] = left_dialog[i-j+n] = right_dialog[i+j] = 0;
          maze[i][j] = '.';
        }
      }
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  Solution s;

  for (int i = 1; i < 20; ++i)
    cout << i << ": " << s.totalNQueens(i) << endl;
  return 0;
} 
