class Solution {
    unordered_map<string, multiset<string>> adjList;
    vector<string> route;
public:
    // Add sol : DFS with backtracking while forcing visiting every edge Time O(V * E) Space O(V + E)
    
    /* 
        Time O(E * logE) Space O(V + E)
        We avoid backtracking by using the existing path and populating the result backwards when retreating 
        Greedy DFS Eulerian Path Hierholzer's Algorithm(Time complexity O(E))
        Eulerian path existance check(not needed in this problem) :
        - At most one vertex has outdegree - indegree = 1(start point) and indegree - outdegree = 1(end point), others have equal in and out degrees
    */
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto &i : tickets) {
            adjList[i[0]].insert(i[1]);
        }
        populateEulerianPath("JFK");
        return vector<string> (route.rbegin(), route.rend());
    }
    void populateEulerianPath(string src) {
        while(adjList[src].size()) {
            string lexSmallestNbr = *adjList[src].begin();
            adjList[src].erase(adjList[src].begin());
            populateEulerianPath(lexSmallestNbr);
        }
        route.push_back(src);
    }
};
