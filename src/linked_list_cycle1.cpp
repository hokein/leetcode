#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// Detect wether a list has a cycle.
// Solution O(n).
//
// Two pointer
//  slow, move one step each time
//  fast, move two steps each time
//
// If meet, then the list has cycle.            
class Solution {
 public:
  bool hasCycle(ListNode *head) {
    if (!head)      
      return false;
    ListNode *p1, *p2;
    p1 = head;
    p2 = p1->next;
    while (p2 && p2->next) {
      if (p2 == p1)
        return true;
      p1 = p1->next;
      p2 = p2->next->next;
    }
    return false;
  }
};

int main() {

  int a[] = {2, 3, 4, 1};
  int len = 3;
  ListNode node(1);
  ListNode* fr = &node;
  for (int i = 0; i < len; ++i) {
    fr->next = new ListNode(a[i]);
    fr = fr->next;
  }
  fr->next = fr;
  Solution s;
  cout << s.hasCycle(node.next) << endl;
  return 0;
} 
