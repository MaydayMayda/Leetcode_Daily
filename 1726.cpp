/**
  ******************************************************************************
  * @number         : 1726
  * @title          : 同积元组
  * @attention      : 数组、哈希表
  * @author         : zzzhou
  * @date           : 2023/10/19
  ******************************************************************************
  */


#include "vector"
#include  "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int>idx;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++)
                idx[nums[i]*nums[j]]++;
        }
        for(auto it:idx){
            ans+=it.second*(it.second-1)*4;
        }
        return ans;
    }
};

int main() {
    vector<int>arr{2,3,4,6,8,12};
    Solution s;
    s.tupleSameProduct(arr);
    return 0;
}