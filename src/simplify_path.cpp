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
  string simplifyPath(string path) {
    vector<string> words = split(path);      
    vector<string> simplified_words;
    for (int i = 0; i < words.size(); ++i)
      if (words[i] == "..") { 
        if (!simplified_words.empty())
          simplified_words.pop_back();
      } else if (words[i] != ".")
        simplified_words.push_back(words[i]);
    string simplified_path = "/";
    for (int i = 0; i < simplified_words.size(); ++i) {
      simplified_path += simplified_words[i] + "/"; 
      if (i == simplified_words.size() - 1)
        simplified_path.erase(simplified_path.size()-1);
    }
    return simplified_path;
  }
  
  vector<string> split(const string& path) {
    vector<string> words;
    for (int pos = 0; pos < path.size();) {
      while (pos < path.size() && path[pos] == '/')
        ++pos;
      string word;
      while (pos < path.size() && path[pos] != '/')
        word += string(1, path[pos++]);
      if (!word.empty())
        words.push_back(word);
    }
    return words;
  }
};

int main() {
  freopen("test.txt", "r", stdin);

  Solution s;
  cout << s.simplifyPath("/Hhp/..///f/R///FM/DPPv///..//") << endl;
  cout << s.simplifyPath("/../") << endl;
  cout << s.simplifyPath("/a/b//c/") << endl;
  return 0;
} 
