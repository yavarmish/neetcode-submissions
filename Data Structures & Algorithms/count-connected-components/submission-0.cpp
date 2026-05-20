class Solution {
public:
    void dfs(int  curNode, vector<vector<int>> &adjList, vector<bool> &visitedNodes) {
        visitedNodes[curNode] = 1;
        for(int &nbr : adjList[curNode]) {     
            if(!visitedNodes[nbr])     
                dfs(nbr, adjList, visitedNodes);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for(const auto &edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        vector<bool> visitedNodes(n, 0);
        int componentCount = 0;
        for(int node = 0; node < n; ++node) {
            if(!visitedNodes[node]) {
                dfs(node, adjList, visitedNodes);
                ++componentCount;
            }
        }
        return componentCount;
    }
};
