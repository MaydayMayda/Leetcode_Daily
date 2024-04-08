/**
  ******************************************************************************
  * @number         : 2609
  * @title          : 最长平衡子字符串
  * @attention      : 字符串
  * @author         : zzzhou
  * @date           : 2023/11/8
  ******************************************************************************
  */


#include "vector"
#include  "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int len = s.length();
        int ans = 0;
        int index = 0;
        while (index<len){
            int one = 0,zero = 0;
            while (s[index] == '0' && index < len)
                index++,zero++;
            while (s[index] == '1' && index < len)
                index++,one++;
            ans = max(ans,2*min(zero,one));
        }
        return ans;
    }
};

int main() {
    string str="01000111";
    Solution s;
    s.findTheLongestBalancedSubstring(str);
    return 0;
}