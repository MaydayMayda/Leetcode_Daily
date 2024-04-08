/**
  ******************************************************************************
  * @number         : 421
  * @title          : 数组中两个数的最大异或值
  * @attention      : 位运算、字典树、数组、哈希表
  * @author         : zzzhou
  * @date           : 2023/11/5
  ******************************************************************************
  */


#include "vector"
#include  "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findMaximumXOR(vector<int> &nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int high_bit = mx ? 31 - __builtin_clz(mx) : -1;

        int ans = 0, mask = 0;
        unordered_set<int> seen;
        for (int i = high_bit; i >= 0; i--) { // 从最高位开始枚举
            seen.clear();
            mask |= 1 << i;
            int new_ans = ans | (1 << i); // 这个比特位可以是 1 吗？
            for (int x : nums) {
                x &= mask; // 低于 i 的比特位置为 0
                if (seen.contains(new_ans ^ x)) {
                    ans = new_ans; // 这个比特位可以是 1
                    break;
                }
                seen.insert(x);
            }
        }
        return ans;
    }
};

int main() {
    vector<int>arr{14,70,53,83,49,91,36,80,92,51,66,70};
    Solution s;
    s.findMaximumXOR(arr);
    return 0;
}