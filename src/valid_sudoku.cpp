#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 10;
class Solution {
 public:
  int boxes[N];
  int rows[N];
  int cols[N];
  bool isValidSudoku(vector<vector<char> > &board) {
    bool vis[N] = {0};
    for (int i = 0; i < 9; ++i) {
      memset(vis, 0, sizeof(vis));
      for (int j = 0; j < 9; ++j) {
        if (board[i][j] == '.')
          continue;
        int val = board[i][j] - '0';
        if (val > 0 && val < 10 && !vis[val]) 
          vis[val] = 1;
        else
          return false;
      }
    }
    for (int i = 0; i < 9; ++i) {
      memset(vis, 0, sizeof(vis));
      for (int j = 0; j < 9; ++j) {
        if (board[j][i] == '.')
          continue;
        int val = board[j][i] - '0';
        if (val > 0 && val < 10 && !vis[val]) 
          vis[val] = 1;
        else
          return false;
      }
    }
    for (int i = 0; i < 9; ++i) {
      int x = i/3*3;
      int y = i%3*3;
      memset(vis, 0, sizeof(vis));
      for (int k = 1; k <= 9; ++k) {
        if (board[x][y] != '.') {
          int val = board[x][y] - '0';
          if (val > 0 && val < 10 && !vis[val])
            vis[val] = 1;
          else
            return false;
        } 
        if (k%3 == 0) {
          ++x;
          y = i%3*3;
        } else {
          ++y;
        }
      }
    }
    return true;
  }
};

class Solution2 {
 public:
  int boxes[N];
  int rows[N];
  int cols[N];
  bool isValidSudoku(vector<vector<char> > &board) {
    memset(boxes, 0, sizeof(boxes));
    memset(rows, 0, sizeof(rows));
    memset(cols, 0, sizeof(cols));  

    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (board[i][j] != '.')
          rows[i] |= 1 << (board[i][j] - '1');
        if (board[j][i] != '.')
          cols[i] |= 1 << (board[j][i] - '1');
        int pos = i/3*3 + j/3;
        boxes[pos] |= 1 << (board[i][j] - '1');
      }
    }

    bool is_valid = true;
    for (int i = 0; i < 9; ++i) {
      int x = i/3*3;
      int y = i%3*3;
      for (int j = 0; j < 3 && is_valid; ++j) {
        if (is_conflict(boxes[i], rows[x+j])
            || is_conflict(boxes[i], cols[y+j]))
          is_valid = false;
      }
    }
    return is_valid;
  }
  bool is_conflict(int a, int b) {
    for (int i = 0; i < N; ++i, a >>= 1, b >>= 1)
      if ((a&1) && b&(1))
        return true;
    return false; 
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  vector<vector<char> > v;
  vector<char> v1;
  char c;
  for (int i = 0; i < 9; ++i) {
    vector<char> v1;
    for (int j = 0; j < 9; ++j) {
      cin >> c;
      v1.push_back(c);
    }
    v.push_back(v1);
  }
  Solution s;
  cout << s.isValidSudoku(v) << endl;
  return 0;
} 
