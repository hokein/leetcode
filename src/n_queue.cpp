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
  const static int N = 20;
  char maze[N][N];
  bool vis_row[N], vis_col[N];
  int n;
  vector<vector<string> > result;
  vector<vector<string> > solveNQueens(int n) {
    this->n = n;
    memset(vis_row, 0, sizeof(vis_row));
    memset(vis_col, 0, sizeof(vis_col));
    memset(maze, '.', sizeof(maze));
    dfs(0, 0, 0);
    return result;
  }

  bool check_dialog(int ii, int jj) {
    for (int i = ii, j = jj; i >= 0 && j >= 0; --i, --j) {
      if (maze[i][j] == 'Q')
        return false;
    }
    for (int i = ii, j = jj; i < n && j < n; ++i, ++j) {
      if (maze[i][j] == 'Q')
        return false;
    }
    for (int i = ii, j = jj; i < n && j >= 0; ++i, --j) {
      if (maze[i][j] == 'Q')
        return false;
    }
    for (int i = ii, j = jj; i >= 0 && j < n; --i, ++j) {
      if (maze[i][j] == 'Q')
        return false;
    }
    return true;
  }
  void dfs(int cnt, int ii, int jj) {
    if (cnt == n) {
      vector<string> one_case;
      for (int i = 0; i < n; ++i) {
        string s(maze[i], maze[i]+n);
        one_case.push_back(s); 
      }
      result.push_back(one_case);
      return;
    }
    for (int i = ii; i < n; ++i)
      for (int j = (i==ii?jj:0); j < n; ++j) {
        if (!vis_row[i] && !vis_col[j]) {
          if (!check_dialog(i, j))
            continue;
          vis_row[i] = vis_col[j] = 1;
          maze[i][j] = 'Q';
          dfs(cnt+1, i, j);
          vis_row[i] = vis_col[j] = 0;
          maze[i][j] = '.';
        }
      }
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  Solution s;

  vector<vector<string> > result = s.solveNQueens(10);
  for (int i = 0; i < result.size(); ++i) {
    for (int j = 0; j < result[i].size(); ++j)
      cout << result[i][j] << endl;
    cout << endl;
  }
  return 0;
}
