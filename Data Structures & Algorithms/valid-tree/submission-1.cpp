class Solution {
public:
    bool markVisitedAndCheckCycles(vector<vector<int>> &adjNodes, vector<bool> &vis, int parentNode, int currentNode) {
        if(vis[currentNode]) return true;
        vis[currentNode] = 1;
        for(int &nbr : adjNodes[currentNode]) {
            if(nbr != parentNode and markVisitedAndCheckCycles(adjNodes, vis, currentNode, nbr)) return true;            
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjNodes(n);
        for(int i = 0; i < edges.size(); ++i) {
            adjNodes[edges[i][0]].push_back(edges[i][1]);
            adjNodes[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> vis(n, false);
        bool hasCycle = markVisitedAndCheckCycles(adjNodes, vis, -1, 0);
        for(const auto &i : vis) if(!i) return false;
        return !hasCycle;
    }
    // Add BFS and DSU
};
