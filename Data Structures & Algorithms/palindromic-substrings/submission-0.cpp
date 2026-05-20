class Solution {
public:
    // Expand around the center Time O(n ^ 2) Space O(1)
    void expandAroundCenter(string &s, int l, int r, int &res) {
        while(l >=0 and r < s.size() and s[l] == s[r]) {
            ++res;
            --l;
            ++r; 
        }
    }
    int countSubstrings(string s) {
        int n = s.size(), res = 0;
        for(int i = 0; i < n; ++i) {
            // odd length substring
            int l = i, r = i;
            expandAroundCenter(s, l, r, res);
            // even length substring
            l = i, r = i + 1;
            expandAroundCenter(s, l, r, res);
        }
        return res;   
    }
};
