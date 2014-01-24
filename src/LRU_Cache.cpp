#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// LRU Cache implementation
//
// stl::map + double_linked_list
// O(log(n))
class LRUCache{
 public:
  struct Node {
    int key;
    int value;
    Node *left, *right;
    Node():key(0), value(0), left(NULL), right(NULL) {}
  };
  Node *head, *rear;
  int max_len;
  map<int, Node*> mp;
  LRUCache(int capacity) {
    // a virtual node, for code convenice.
    rear = head = new Node();
    max_len = capacity;
    mp.clear();
  }
  ~LRUCache() {
    while (rear) {
      Node* tmp = rear->left;
      delete rear;
      rear = tmp;
    }
  }
  int get(int key) {
    if (mp.find(key) == mp.end())
      return -1;
    Node *p = mp[key];
    update_vis(key);
    return p->value;
  }
  void update_vis(int key) {
    if (mp.find(key) == mp.end())
      return;
    Node *p = mp[key];
    // Optimize: if vis (key, value) has been already in the end, no need to update.
    if (p != rear) {
      p->left->right = p->right;
      p->right->left = p->left;
      rear->right = p;
      p->right = NULL;
      p->left = rear;
      rear = p;
    }
  }
  void set(int key, int value) {
    if (mp.find(key) != mp.end()) {
      mp[key]->value = value;
      update_vis(key);
    } else {
      // delete the first node.
      if (mp.size() >= max_len) {
        Node* delete_node = head->right;
        mp.erase(delete_node->key);
        head->right = delete_node->right;
        if (head->right)
          head->right->left = head;
        if (rear == delete_node)
          rear = rear->left;
        delete delete_node;
      }
      // Add new Node at the end.
      Node* new_node = new Node();
      new_node->key = key;
      new_node->value = value;
      rear->right = new_node;
      new_node->left = rear;
      rear = new_node;
      mp[key] = rear;
    }    
  }
};

int main() {
  LRUCache lru(2);
  lru.set(2,1);
  lru.set(1,1);
  lru.set(2,3);
  lru.set(4,1);
  cout << lru.get(1) << endl;
  cout << lru.get(2) << endl;
  return 0;
} 
