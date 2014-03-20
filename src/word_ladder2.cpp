#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <map>
#include <string>
#include <unordered_map>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// BFS: need to output all possible paths.
class Solution {
public:
	unordered_map<string, vector<string> > parents; // record son => father information.
	vector<vector<string> > ans;
	vector<string> path;

	vector<vector<string> > findLadders(string start,
		string end, unordered_set<string> &dict) {
		unordered_set<string> cur, next; // two layer.
		unordered_set<string> vis;
		ans.clear();
		parents.clear();

		cur.insert(start);
		parents[start].push_back("");
		bool is_reached = 0;
		while (!cur.empty()) {
			for (const string& s : cur)
				vis.insert(s);

      // calculate next layer from cur layer.
			for (const string& s : cur) {
				string new_word(s);
				for (int i = 0; i < s.size(); ++i) {
					char c = new_word[i];	
					for (int j = 'a'; j <= 'z'; ++j) {
						if (j == c) continue;
						new_word[i] = j;
						if ((dict.find(new_word) != dict.end() || new_word == end)
                && vis.find(new_word) == vis.end()) {
							next.insert(new_word);
							parents[new_word].push_back(s); // new_state => old_state
							if (new_word == end)
								is_reached = 1;
						}	
					}
					new_word[i] = c;
				}
			}

			swap(cur, next);
			next.clear();
			if (is_reached) {
				path.clear();
				path.push_back(end);
				gen_path(end, start);
				break;
			}
		}
		return ans;
	}

	inline void gen_path(const string& s, const string& start) {
		if (s == start) {
			ans.push_back(path);
			reverse(ans.back().begin(), ans.back().end());
			return;
		}
		for (int i = 0; i < parents[s].size(); ++i) {
			path.push_back(parents[s][i]);
			gen_path(parents[s][i], start);
			path.pop_back();
		}
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
	string end = "cog";
	Solution s;
	vector<vector<string> > ans = s.findLadders(start, end, dict);
	for (int i = 0; i < ans.size(); ++i) {
		for (int j = 0; j < ans[i].size(); ++j) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}
