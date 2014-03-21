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
  bool boxes[N][N];
  bool rows[N][N];
  bool cols[N][N];

  void solveSudoku(vector<vector<char> > &board) {
    memset(boxes, 0, sizeof(boxes));        
    memset(rows, 0, sizeof(rows));        
    memset(cols, 0, sizeof(cols));        
    
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        if (board[i][j] != '.')
          rows[i][board[i][j]-'0'] = 1; 
        if (board[j][i] != '.')
          cols[i][board[j][i]-'0'] = 1;
        int pos = i/3*3 + j/3;
        if (board[i][j] != '.')
          boxes[pos][board[i][j]-'0'] = 1;
      }
    }
    dfs(0, 0, board);
  }

  bool dfs(int x, int y, vector<vector<char> > &board) {
    for (int i = x; i < 9; ++i)
      for (int j = i==x?y:0; j < 9; ++j) {
        if (board[i][j] == '.') {
          for (int k = 1; k <= 9; ++k) {
            if (!rows[i][k] && !cols[j][k]) {
              int pos = i/3*3 + j/3;
              if (!boxes[pos][k]) {
                board[i][j] = '0' + k;
                rows[i][k] = cols[j][k] = boxes[pos][k] = 1;
                if (dfs(x, y+1, board))
                  return true;
                board[i][j] = '.';
                rows[i][k] = cols[j][k] = boxes[pos][k] = 0;
              }
            }
          }
          return false;
        }
      }
    return true;
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
  s.solveSudoku(v);
  for (int i = 0; i < v.size(); ++i) {
    for (int j = 0; j < v[i].size(); ++j)
      cout << v[i][j];
    cout << endl;
  }
  return 0;
} 
