#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// DP solution the same as problem: word break 1
class Solution {
public:
	vector<string> ans;
	vector<string> path;
	string ss;
	vector<string> wordBreak(string s, unordered_set<string> &dict) {
		ss = s;
		ans.clear();
		path.clear();

		vector<bool> dp(s.size() + 1, 0);
    // record the break position.
    // parents[i][j]: s[j..i-1] is a valid word, can be break at position j.
		vector<vector<bool> > parents(s.size()+1, vector<bool>(s.size()+1, 0));
		dp[0] = 1;
		for (int i = 1; i <= s.size(); ++i) {
			for (int j = 0; j < i; ++j) {
				if (dp[j] && dict.find(string(s.begin() + j, s.begin() + i)) != dict.end()) {
					dp[i] = 1;
					parents[i][j] = 1;
				}
			}
		}
		gen_path(s.size(), parents);
		return ans;
	}

	void gen_path(int cur, vector<vector<bool> >& parents) {
		if (cur == 0) {
			string sentence;
			for (int i = path.size()-1; i >= 0; --i)
				sentence += (path[i] + " ");
			sentence.pop_back();
			ans.push_back(sentence);
			return;
		}
		for (int i = 0; i < cur; ++i) {
			if (parents[cur][i]) {
				path.push_back(string(ss.begin() + i, ss.begin() + cur));
				gen_path(i, parents);
				path.pop_back();
			}
		}
	}
};

int main() {
  freopen("test.txt", "r", stdin);
  unordered_set<string> dict;
	dict.insert("cat");
	dict.insert("cats");
	dict.insert("and");
	dict.insert("sand");
	dict.insert("dog");
	dict.insert("leet");
	dict.insert("code");
	Solution s;
	vector<string> ans = s.wordBreak("catsanddog", dict);
  return 0;
} 
