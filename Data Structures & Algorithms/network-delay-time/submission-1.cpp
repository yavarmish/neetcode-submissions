class Solution {
public:
    /*
        BFS from source node with edge relaxation updating other nodes if smaller path exists
        Similar to Bellman-Ford(where instead edges are relaxed V - 1 times)
        Each node can be processed multiple times if shorter path is found
        Time O(N * E) Space O(N + E)
    */
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adjList(n + 1);
        for(auto& time: times) {
            adjList[time[0]].push_back({time[1], time[2]});
        }
        vector<int> dist(n + 1, INT_MAX);
        queue<pair<int, int>> nodeTimeQueue;
        nodeTimeQueue.push({k, 0});
        dist[k] = dist[0] = 0;

        while(nodeTimeQueue.size()) {
            auto& [node, time] = nodeTimeQueue.front();
            nodeTimeQueue.pop();
            if(time > dist[node]) continue; // Avoids redundant processing
            for(auto &nbrs : adjList[node]) {
                int nbr = nbrs.first, weight = nbrs.second;
                if(time + weight < dist[nbr]) {
                    dist[nbr] = time + weight;
                    nodeTimeQueue.push({nbr, time + weight});
                } 
            }            
        }
        int res = 0;
        for(auto &i : dist) res = max(res, i);
        return res == INT_MAX ? -1 : res;
    }
};
