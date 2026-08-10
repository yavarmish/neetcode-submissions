class Solution {
public:
    string topologicalSort(unordered_map<char, vector<char>> &adj, unordered_map<char, int> &indegree) {
        queue<char> bfsQueue;
        string result = "";

        // Push all characters with an in-degree of 0 into the queue
        for(auto &[ch, count] : indegree) {
            if(count == 0) {
                bfsQueue.push(ch);
            }
        }

        // Process the queue
        while(!bfsQueue.empty()) {
            char current = bfsQueue.front();
            bfsQueue.pop();
            result += current;

            // Decrease the in-degree of all neighbors
            for(char neighbor : adj[current]) {
                indegree[neighbor]--;
                // If in-degree becomes 0, it's ready to be added to the queue
                if(indegree[neighbor] == 0) {
                    bfsQueue.push(neighbor);
                }
            }
        }

        // Cycle Detection
        if(result.size() == indegree.size()) 
            return result;
        
        // Cycle detected
        else return ""; 
    }

    string foreignDictionary(vector<string>& words) {
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> indegree;

        // Initialize in-degree of ALL unique characters to 0
        for(const string& word : words) {
            for(char c : word) {
                indegree[c] = 0;
            }
        }

        // Build the graph by comparing adjacent words only
        for(int i = 0; i < words.size() - 1; ++i) {
            string w1 = words[i];
            string w2 = words[i + 1];
            int len = min(w1.size(), w2.size());

            // Check for invalid prefix case (e.g., "abc" comes before "ab")
            if(w1.size() > w2.size() && w1.substr(0, len) == w2) {
                return "";
            }

            // Find the first mismatch and create a directed edge
            for(int k = 0; k < len; ++k) {
                if(w1[k] != w2[k]) {
                    adj[w1[k]].push_back(w2[k]);
                    indegree[w2[k]]++;
                    break; // Only the first differing character gives us order
                }
            }
        }

        // Kahn's algorithm
        return topologicalSort(adj, indegree);
    }
};