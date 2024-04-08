/**
  ******************************************************************************
  * @number         : 2525
  * @title          : 根据规则将箱子分类
  * @attention      : 数学
  * @author         : zzzhou
  * @date           : 2023/10/20
  ******************************************************************************
  */


#include "vector"
#include  "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        bool x = length >= 10000 || width >= 10000 || height >= 10000 || 1LL * length * width * height >= 1000000000;
        bool y = mass >= 100;
        if (x && y) return "Both";
        if (x) return "Bulky";
        if (y) return "Heavy";
        return "Neither";
    }
};

int main() {
    int length,width,height,mass;
    Solution s;
    s.categorizeBox();
    return 0;
}