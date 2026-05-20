class Solution {
public:
    // Expand around the center Time O(n ^ 2) Space O(1)
    void expandAroundCenter(string &s, int l, int r, int &resIdx, int &resLen) {
        while(l >=0 and r < s.size() and s[l] == s[r]) {
            // cout<<l<<" "<<r<<"\n";
            if(resLen < r - l + 1) {
                resIdx = l;
                resLen = r - l + 1;
            }
            --l;
            ++r; 
        }
    }
    string longestPalindrome(string s) {
        int n = s.size(), resIdx, resLen = 0;

        for(int i = 0; i < n; ++i) {
            // odd length substring
            int l = i, r = i;
            expandAroundCenter(s, l, r, resIdx, resLen);
            // even length substring
            l = i, r = i + 1;
            expandAroundCenter(s, l, r, resIdx, resLen);            
        }
        return s.substr(resIdx, resLen);    
    }

};
