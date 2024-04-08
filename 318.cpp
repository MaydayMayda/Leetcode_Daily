/**
  ******************************************************************************
  * @number         : 318
  * @title          : 最大单词长度乘积
  * @attention      : 位运算、数组、字符串
  * @author         : zzzhou
  * @date           : 2023/11/6
  ******************************************************************************
  */


#include "vector"
#include  "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        int mask[n];
        memset(mask, 0, sizeof(mask));
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (char& c : words[i]) {
                mask[i] |= 1 << (c - 'a');
            }
            for (int j = 0; j < i; ++j) {
                if ((mask[i] & mask[j]) == 0) {
                    ans = max(ans, (int) (words[i].size() * words[j].size()));
                }
            }
        }
        return ans;
    }
};


int main() {
    vector<string>arr{"abcw","baz","foo","bar","xtfn","abcdef"};
    Solution s;
    s.maxProduct(arr);
    return 0;
}