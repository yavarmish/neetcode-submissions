/*
    DSU
    - findParent
    - union(by rank/size)
    
    -- By rank(analogous to height, path compression might change height but not rank)
    - Initial state : parent = node, rank = 0
    - Find ultimate parent
    - Connect smaller rank to larger one

    -- By size
    - Initial state : parent = node, size = 1
    - Find ultimate parent
    - Connect smaller size to larger one
*/
class DisjointSet {
    vector<int> parent;
    vector<int> rank;
    vector<int> size;
    public:
    DisjointSet(int &n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for(int  i = 0; i < n + 1; ++i)
            parent[i] = i;
    }
    int findParent(int &u) {
        if(parent[u] == u) return u;
        else return parent[u] = findParent(parent[u]);
    }        
    void unionByRank(int &u, int &v) {
        int upu = findParent(u), upv = findParent(v);
        if(upu == upv) return;
        if(rank[upv] == rank[upu]) ++rank[upu];
        if(rank[upu] < rank[upv]) {
            parent[upu] = upv;
        }
        else {
            parent[upv] = upu;
        }
    }
    void unionBySize(int &u, int &v) {
        int upu = findParent(u), upv = findParent(v);
        if(upu == upv) return;
        if(size[upu] < size[upv]) {
            parent[upu] = upv;
            size[upv] += size[upu];
        }
        else {
            parent[upv] = upu;
            size[upu] += size[upv];
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet groupedEdges(n);
        for(vector<int> &edge : edges) {
            if(groupedEdges.findParent(edge[0]) == groupedEdges.findParent(edge[1])) return {edge[0], edge[1]};
            groupedEdges.unionByRank(edge[0], edge[1]);            
        }
        return {-1, -1};
    }
};
