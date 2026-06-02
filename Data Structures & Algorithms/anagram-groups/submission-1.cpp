class Solution {
public:
    // Time O(m*n) Space -> O(m*n)
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groupedStrings;
        vector<int> freq(26, 0);
        for(auto &str : strs) {
            fill(freq.begin(), freq.end(), 0);
            for(auto &ch : str) {
                ++freq[ch - 'a'];
            }
            string keyString;
            for(int i = 0; i < 26; ++i) {
                if(freq[i]) {
                    char ch = ('a' + i);
                    keyString += (ch + to_string(freq[i]));
                }
            }
            groupedStrings[keyString].push_back(str);
        }
        vector<vector<string>> res;
        for(auto &[key, val] : groupedStrings) {
            res.push_back(val);
        }
        return res;
    }
    /*
    n->number of string, m-> length of longes string 
    Time -> O(n * m * log(m)) 
    Space -> O(n * m)
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groupedAnagrams;

        for(auto &str : strs) {
            string sortedKey = str;
            sort(sortedKey.begin(), sortedKey.end());
            groupedAnagrams[sortedKey].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto &[key, anagramList] : groupedAnagrams) {
            ans.push_back(anagramList);
        }
        return ans;
    }
    */
};
