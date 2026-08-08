#define MAX_DIST 1e8
class Solution {
    unordered_map<int, vector<pair<int, int>>> adj;
public:
    void getLastTime(int src, vector<int> &res) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> bfsQueue;
        bfsQueue.push({0, src});
        while(bfsQueue.size()) {
            auto [time, node] = bfsQueue.top();
            bfsQueue.pop();
            if(time > res[node]) continue;
            for(auto &[nbrNode, delay] : adj[node]) {
                int curTime = time + delay;
                if(curTime < res[nbrNode]) {
                    res[nbrNode] = curTime;
                    bfsQueue.push({curTime, nbrNode});
                }
            }
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for(auto &time : times) {
            adj[time[0]].push_back({time[1], time[2]});
        }
        vector<int> res(n + 1, MAX_DIST);
        res[k]= 0;
        getLastTime(k, res);
        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            ans = max(ans, res[i]);
        }
        return ans == MAX_DIST ? -1 : ans;
    }
};
