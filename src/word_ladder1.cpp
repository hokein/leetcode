#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// BFS
class Solution {
public:
	int ladderLength(string start, string end, unordered_set<string> &dict) {
		typedef pair<string, int> P;
		queue<P> q;
		unordered_set<string> vis;
		q.push(P(start, 1));
		vis.insert(start);
		int steps = 1;
		while (!q.empty()) {
			P cur = q.front();
			q.pop();
			if (is_valid(cur.first, end))
				return cur.second + 1;
			for (int i = 0; i < cur.first.size(); ++i) {
				char c = cur.first[i];
				for (int j = 'a'; j <= 'z'; ++j) {
					cur.first[i] = j;
					if (dict.find(cur.first) != dict.end() && vis.find(cur.first) == vis.end()) {
						vis.insert(cur.first);
						q.push(P(cur.first, cur.second + 1));
					}
				}
				cur.first[i] = c;
			}
		}
		return 0;
	}

	bool is_valid(const string& a, const string& b) {
		int cnt = 0;
		for (int i = 0; i < a.size(); ++i)
		if (a[i] != b[i])
			++cnt;
		return cnt == 1;
	}
};


int main() {
  freopen("test.txt", "r", stdin);

  unordered_set<string> dict;
  dict.insert("hot");
  dict.insert("dot");
  dict.insert("dog");
  dict.insert("lot");
  dict.insert("log");
  string start = "hit";
  string end = "hit";
  Solution s;
  cout << s.ladderLength(start, end, dict) << endl;
  return 0;
} 
