#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// Using STL::list
class LRUCache{
 public:
  struct Node {
    int key;
    int value;
    Node() {}
    Node(int a, int b): key(a), value(b) {}
  };
  list<Node> double_linked_list;
  int max_len;
  // key => iterator in double linked list.
  map<int, list<Node>::iterator> mp;
  LRUCache(int capacity) {
    max_len = capacity;
    mp.clear();
  }
  int get(int key) {
    if (mp.find(key) == mp.end())
      return -1;
    list<Node>::iterator it = mp[key];
    update_vis(it->key);
    return it->value;
  }
  void update_vis(int key) {
    if (mp.find(key) == mp.end())
      return;
    list<Node>::iterator it = mp[key];
    Node node = *it;
    double_linked_list.erase(it);
    double_linked_list.push_back(node);
    // update key iterator.
    mp[key] = --double_linked_list.end();
  }
  void set(int key, int value) {
    if (mp.find(key) != mp.end()) {
      mp[key]->value = value;
      update_vis(key);
    } else {
      // delete the first node.
      if (mp.size() >= max_len) {
        mp.erase((double_linked_list.begin())->key);
        double_linked_list.erase(double_linked_list.begin());
      }
      double_linked_list.push_back(Node(key, value));
      mp[key] = --double_linked_list.end();
    }    
  }
};

int main() {
  freopen("test.txt", "r", stdin);
  LRUCache lru(2);
  lru.set(2,1);
  lru.set(1,1);
  lru.set(2,3);
  lru.set(4,1);
  cout << lru.get(1) << endl;
  cout << lru.get(2) << endl;
  return 0;
} 

