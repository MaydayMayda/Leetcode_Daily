/**
  ******************************************************************************
  * @number         : 1402
  * @title          : 做菜顺序
  * @attention      : 贪心、数组、动态规划、排序
  * @author         : zzzhou
  * @date           : 2023/10/22
  ******************************************************************************
  */


#include "vector"
#include  "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.rbegin(),satisfaction.rend());
        int ans=0;
        int sum=0,sum_back=0;
        int i=0;
        for(;i<satisfaction.size();i++){
            if(satisfaction[i]>=0){
                sum += satisfaction[i];
                continue;
            } else{
                if (sum_back+sum+satisfaction[i] >= 0)
                    sum_back +=  satisfaction[i];
                else
                    break;
            }
        }
        int j=0;
        while((i-1) >= 0){
            ans += satisfaction[j]*i;
            j++;
            i--;
        }
        return ans;
    }
};

int main() {
    vector<int>sat{-1,-8,0,5,-7};
    Solution s;
    s.maxSatisfaction(sat);
    return 0;
}