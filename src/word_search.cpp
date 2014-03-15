#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

class Solution {
public:
  vector<vector<char> > maze;
  vector<vector<bool> > vis;
  string word;
  int n, m;
  bool exist(vector<vector<char> > &board, string word) {
    if (word.empty())
      return true;
    maze = board; 
    this->word = word;
    n = board.size();
    m = board[0].size();
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        if (board[i][j] == word[0]) {
          vis = vector<vector<bool> > (n, vector<bool>(m, 0));
          vis[i][j] = 1;
          if (dfs(i, j, 1))
            return true;
        }
    return false;
  }

  bool dfs(int ii, int jj, int pos) {
    if (pos >= word.size())
      return true;
    for (int i = 0; i < 4; ++i) {
      int x = ii + dx[i];
      int y = jj + dy[i];
      if (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y]) {
        if (maze[x][y] == word[pos]) {
          vis[x][y] = 1;
          if (dfs(x, y, pos+1))
            return true;
          vis[x][y] = 0;
        }
      }
    }
    return false;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  vector<char> v1;
  v1.push_back('A');
  v1.push_back('B');
  v1.push_back('C');
  v1.push_back('E');
  vector<char> v2;
  v2.push_back('S');
  v2.push_back('F');
  v2.push_back('E');
  v2.push_back('S');
  vector<char> v3;
  v3.push_back('A');
  v3.push_back('D');
  v3.push_back('E');
  v3.push_back('E');
  vector<vector<char> > maze;
  maze.push_back(v1);
  maze.push_back(v2);
  maze.push_back(v3);
  Solution s;
  cout << s.exist(maze, "ABCESEEEFS") << endl;
  cout << s.exist(maze, "SEE") << endl;
  cout << s.exist(maze, "ABCB") << endl;
  return 0;
} 
