/**
  ******************************************************************************
  * @number         : 2103
  * @title          : 环和杆
  * @attention      : 哈希表、字符串
  * @author         : zzzhou
  * @date           : 2023/11/2
  ******************************************************************************
  */


#include "vector"
#include  "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int countPoints(string rings) {
        int len = rings.length();
        if (rings.length() < 3)return 0;
        unordered_map<int,vector<char>> idx;
        for (int i=0;i<rings.length();i+=2){
            if(count(idx[rings[i + 1] - '0'].begin(), idx[rings[i + 1] - '0'].end(),rings[i])==0)
                idx[rings[i+1]-'0'].push_back(rings[i]);
        }
        int ans=0;
        for (auto it:idx){
            if(it.second.size()==3)ans++;
        }
        return ans;
    }
};

int main() {
    string rings="B0B6G0R6R0R6G9";
    Solution s;
    s.countPoints(rings);
    return 0;
}