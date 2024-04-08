/**
  ******************************************************************************
  * @number         : 2009
  * @title          : 使数组连续的最少操作数
  * @attention      : 数组、哈希表、二分查找、滑动窗口
  * @author         : zzzhou
  * @date           : 2024/4/8
  ******************************************************************************
  */


#include <vector>
#include <algorithm> // For std::sort and std::unique

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        // 去重
        int m = unique(nums.begin(), nums.end()) - nums.begin();
        int ans = 0, left = 0;
        for (int i = 0; i < m; i++) {
            while (left < n && nums[left] < nums[i] - n + 1) { // nums[left] 不在窗口内
                left++;
            }
            ans = max(ans, i - left + 1);
        }
        return n - ans;
    }
};

int main() {
    vector<int> arr1{4,2,5,3};
    Solution s;
    s.minOperations(arr1);
    return 0;
}

