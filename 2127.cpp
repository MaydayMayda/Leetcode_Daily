/**
  ******************************************************************************
  * @number         : 2127
  * @title          : 参加会议的最多员工数
  * @attention      : 深度优先搜索、图、拓扑排序
  * @author         : zzzhou
  * @date           : 2023/11/1
  ******************************************************************************
  */


#include "vector"
#include  "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        int ans;

/*
 * 因为每个人都有自己喜欢的员工（每个节点的出度一定为1），所以这其中是一定有环的，这个环叫基环，剩下的是树枝
 * 基环环有两种情况，等于2，或者大于2
 * 基环大于2的话，找最大的环就ok了，因为树枝再长也无法坐在一块
 * 基环等于2的话，就需要找到两个节点分别最长的链，再拼在一起
*/
//        统计节点的入度
        vector<int>deg(n);
        for(auto it:favorite)
            deg[it]++;
//        把入度为0的节点压入队列中
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (deg[i] == 0) q.push(i);
//        拓扑排序，把树枝剪掉
        vector<int> max_depth(n, 1);
        while(!q.empty()){
            int x = q.front();
            q.pop();
            int y = favorite[x]; // x 只有一条出边
            max_depth[y] = max_depth[x] + 1;
            if (--deg[y] == 0)
                q.push(y);
        }
//        根据基环的情况，开始分情况计算
        int max_ring_size = 0, sum_chain_size = 0;
        for (int i=0;i<n;i++){
            if (deg[i] == 0) continue;
            // 遍历基环上的点
            deg[i] = 0; // 将基环上的点的入度标记为 0，避免重复访问
            int ring_size = 1; // 基环长度
            for (int x = favorite[i]; x != i; x = favorite[x]) {
                deg[x] = 0; // 将基环上的点的入度标记为 0，避免重复访问
                ring_size++;
            }
            if (ring_size == 2) { // 基环长度为 2
                sum_chain_size += max_depth[i] + max_depth[favorite[i]]; // 累加两条最长链的长度
            } else {
                max_ring_size = max(max_ring_size, ring_size); // 取所有基环长度的最大值
            }
        }
        return ans;
    }
};

int main() {
    vector<int>favorite{1,0,0,2,2,4,1};
    Solution s;
    s.maximumInvitations(favorite);
    return 0;
}