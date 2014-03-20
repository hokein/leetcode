#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 500;
bool vis[N][N];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

// BFS
class Solution {
 public:
  int n, m;
  void solve(vector<vector<char> > &board) {
    if (board.empty())
      return;
    n = board.size();
    m = board[0].size();
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; ++i)  
      for (int j = 0; j < m; ++j)
        if (!vis[i][j] && board[i][j] == 'O'
            && !(i == 0 || j == 0 || i == n-1 || j == m-1))
          bfs(i, j, board);
  }

  void bfs(int x, int y, vector<vector<char> > &board) {
    typedef pair<int, int> P;
    queue<P> q;
    vis[x][y] = 1;
    q.push(P(x, y));
    vector<P> result;
    bool is_valid = 1;
    while (!q.empty()) {
      P cur = q.front();
      q.pop();
      result.push_back(cur);
      for (int i = 0; i < 4; ++i) {
        int new_x = cur.first + dx[i];
        int new_y = cur.second + dy[i];
        if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m
            && !vis[new_x][new_y] && board[new_x][new_y] == 'O') {
          result.push_back(P(new_x, new_y));
          vis[new_x][new_y] = 1;
          q.push(P(new_x, new_y));
          if (new_x == 0 || new_x == n-1 || new_y == 0 || new_y == m-1)
            is_valid = false;
        }
      }
    }
    if (is_valid) {
      for (int i = 0; i < result.size(); ++i)
        board[result[i].first][result[i].second] = 'X';
    }
  }
};

int main() {
  freopen("test.txt", "r", stdin);
  vector<vector<char> > board;
  vector<char> v1;
  v1.push_back('X');
  v1.push_back('X');
  v1.push_back('X');
  v1.push_back('X');
  vector<char> v2;
  v2.push_back('X');
  v2.push_back('O');
  v2.push_back('O');
  v2.push_back('X');
  vector<char> v3;
  v3.push_back('X');
  v3.push_back('X');
  v3.push_back('O');
  v3.push_back('X');
  vector<char> v4;
  v4.push_back('X');
  v4.push_back('O');
  v4.push_back('O');
  v4.push_back('X');
  board.push_back(v1);
  board.push_back(v2);
  board.push_back(v3);
  board.push_back(v4);
  Solution s;
  s.solve(board);
  for (int i = 0; i < board.size(); ++i) {
    for (int j = 0; j < board[i].size(); ++j) {
      cout << board[i][j];
    }
    cout << endl;
  }
  return 0;
} 
