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
  string roman_nums;
  string convert_roman(int n, char one, char five, char ten) {
    if (n == 0)
      return "";
    if (n == 1)
      return string(1, one); 
    if (n >= 2 && n <= 3)
      return string(n, one);
    if (n == 4) {
      string ans(1, one);
      ans = ans + five;
      return ans;
    } 
    if (n == 5)
      return string(1, five);
    if (n > 5 && n < 9) {
      string ans(1, five);
      for (int i = 0; i < n-5; ++i)
        ans = ans + one;
      return ans;
    }
    if (n == 9) {
      string ans(1, one);
      ans = ans + ten;
      return ans;  
    }
  }
  string intToRoman(int num) {
    roman_nums = "IVXLCDMXX"; // last two characters are mock digits.
    string ans;
    int cnt = 0;
    while (num) {
      ans = convert_roman(num%10, roman_nums[cnt], roman_nums[cnt+1],
                          roman_nums[cnt+2]) + ans;
      cnt += 2;
      num /= 10; 
    }      
    return ans;
  }
};

int main() {
  freopen("test.txt", "r", stdin);
  Solution s;
  cout << s.intToRoman(1066) << endl;
  return 0;
} 
