#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// Definition for undirected graph.
struct UndirectedGraphNode {
  int label;
  vector<UndirectedGraphNode *> neighbors;
  UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
 public:
  map<int, UndirectedGraphNode*> map_nodes;
  set<int> vis;
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if (node == NULL)
      return NULL;
    map_nodes.clear();
    vis.clear();
    dfs(node);
    return map_nodes[node->label];
  }

  UndirectedGraphNode * findOrCreateNode(int label) {
    if (map_nodes.find(label) == map_nodes.end())
      map_nodes[label] = new UndirectedGraphNode(label);
    return map_nodes[label];
  }

  void dfs(UndirectedGraphNode* node) {
    vis.insert(node->label);
    if (map_nodes.find(node->label) == map_nodes.end())
      map_nodes[node->label] = new UndirectedGraphNode(node->label);
    for (int i = 0; i < (node->neighbors).size(); ++i) {
      int label = (node->neighbors[i])->label;
      map_nodes[node->label]->neighbors.push_back(findOrCreateNode(label));
      if (vis.find(label) == vis.end()) {
        dfs(node->neighbors[i]);
      }
    }
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  return 0;
} 
