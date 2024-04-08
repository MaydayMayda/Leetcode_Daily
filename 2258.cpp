/**
  ******************************************************************************
  * @number         : 2258
  * @title          : 逃离火灾
  * @attention      : 广度优先搜索、数组、二分查找、矩阵
  * @author         : zzzhou
  * @date           : 2023/11/9
  ******************************************************************************
  */


#include "vector"
#include  "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        int col = 0,row = 0,deep = 0,time = 0;
        while(true){

        }
        return time;
    }
};

int main() {
    vector<vector<int>>grid{{0,2,0,0,0,0,0},
                            {0,0,0,2,2,1,0},
                            {0,2,0,0,1,2,0},
                            {0,0,2,2,2,0,2},
                            {0,0,0,0,0,0,0}};
    Solution s;
    s.maximumMinutes(grid);
    return 0;
}