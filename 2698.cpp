/**
  ******************************************************************************
  * @number         : 2698
  * @title          : 求一个整数的惩罚数
  * @attention      : 数学、回溯
  * @author         : zzzhou
  * @date           : 2023/10/25
  ******************************************************************************
  */


#include "vector"
#include  "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool check(int i,string nums,int sum,int idx){
        if (idx == nums.length())return sum == i;
        int temp=0;
        for(int m=idx;m<nums.size();m++){
            temp = temp*10*(nums[m]-'0');
            if (temp+sum > i)return false;
            if (check(i,nums,temp+sum,m+1))return true;
        }
        return false;
    }
    int punishmentNumber(int n) {
        string nums;
        int ans=0;
        for(int i=1;i<=n;i++){
            nums = to_string(i*i);
            if(check(i,nums,0,0)) ans++;
        }
        return ans;
    }
};

int main() {
    int n=37;
    Solution s;
    s.punishmentNumber(n);
    return 0;
}