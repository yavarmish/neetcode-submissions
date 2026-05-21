class Solution {
public:
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
};
