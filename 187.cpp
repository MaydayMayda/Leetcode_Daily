/**
  ******************************************************************************
  * @number         : 187
  * @title          : 重复的DNA序列
  * @attention      : 位运算、哈希表、字符串、滑动窗口、哈希函数、滚动哈希
  * @author         : zzzhou
  * @date           : 2023/11/5
  ******************************************************************************
  */


#include "vector"
#include  "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>ans;
        unordered_map<string ,int>idx;
        int len = s.length();
        if(len<10) return ans;
        int start=0,n=10;
        while(start<=len-10){
            string temp;
            temp = s.substr(start,n);
            idx[temp]++;
            start++;
        }
        for(auto it:idx)
            if(it.second>1)ans.push_back(it.first);
        return ans;
    }
};

int main() {
    string str="AAAAAAAAAAA";
    Solution s;
    s.findRepeatedDnaSequences(str);
    return 0;
}