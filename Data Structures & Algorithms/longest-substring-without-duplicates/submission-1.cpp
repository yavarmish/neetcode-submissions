class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, n = s.size(), maxWindow = 0;
        unordered_map<char, bool> charFreq;
        while(j < n) {   
            while(charFreq[s[j]]) {
                charFreq[s[i]] = false;
                i++;
            }
            charFreq[s[j]] = true;
            maxWindow = max(maxWindow, j - i + 1);
            j++;
        }
        return maxWindow;
    }
};
