class Solution {
    unordered_map<string, multiset<string>> targets;
    vector<string> route;
public:
    void visit(string airport) {
        while (targets[airport].size()) {
            string next = *targets[airport].begin();
            targets[airport].erase(targets[airport].begin());
            visit(next);
        }
        route.push_back(airport);
    }
    vector<string> findItinerary(vector<vector<string>> &tickets) {
        for (auto ticket : tickets)
            targets[ticket[0]].insert(ticket[1]);
        visit("JFK");
        return vector<string>(route.rbegin(), route.rend());
    }
};




