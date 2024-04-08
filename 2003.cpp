/**
  ******************************************************************************
  * @number         : 2003
  * @title          : 每棵子树内缺失的最小基因值
  * @attention      : 树、深度优先搜索、并查集、动态规划
  * @author         : zzzhou
  * @date           : 2023/10/31
  ******************************************************************************
  */


#include "vector"
#include  "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> smallestMissingValueSubtree(vector<int> &parents, vector<int> &nums) {
        int n = parents.size();
        vector<int> ans(n, 1);
        auto it = find(nums.begin(), nums.end(), 1);
        if (it == nums.end()) { // 不存在基因值为 1 的点
            return ans;
        }

        // 建树
        vector<vector<int>> g(n);
        for (int i = 1; i < n; i++) {
            g[parents[i]].push_back(i);
        }

        unordered_set<int> vis;
        function<void(int)> dfs = [&](int x) -> void {
            vis.insert(nums[x]); // 标记基因值
            for (int son: g[x]) {
                if (!vis.count(nums[son])) {
                    dfs(son);
                }
            }
        };

        int mex = 2; // 缺失的最小基因值
        int node = it - nums.begin();
        while (node >= 0) {
            dfs(node);
            while (vis.count(mex)) { // node 子树包含这个基因值
                mex++;
            }
            ans[node] = mex; // 缺失的最小基因值
            node = parents[node]; // 往上走
        }
        return ans;
    }
};

int main() {
    vector<int>arr1{-1,0,1,0,3,3},arr2{5,4,6,2,1,3};
    Solution s;
    s.smallestMissingValueSubtree(arr1,arr2);
    return 0;
}