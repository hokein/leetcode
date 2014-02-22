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
  int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    vector<vector<int> > dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));

    dp[0][0] = obstacleGrid[0][0] == 0;

    for (int i = 0; i < obstacleGrid.size(); ++i) {
      for (int j = 0; j < obstacleGrid[i].size(); ++j) {
        if (i-1 >= 0 && obstacleGrid[i-1][j] == 0 && obstacleGrid[i][j] == 0)
          dp[i][j] += dp[i-1][j];
        if (j-1 >= 0 && obstacleGrid[i][j-1] == 0 && obstacleGrid[i][j] == 0)
          dp[i][j] += dp[i][j-1];
      }
    } 
    return dp[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  int data[][3] = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};

  vector<vector<int> > maze;
  for (int i = 0; i < 3; ++i) {
    maze.push_back(vector<int>());
    for (int j  = 0; j < 3; ++j)
      maze[i].push_back(data[i][j]);
  }
  Solution s;
  cout << s.uniquePathsWithObstacles(maze) << endl;
  return 0;
} 
