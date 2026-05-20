class Solution {
public:
    // Bruteforce Time O(n ^ 3) Space O(1)
    bool isPalindrome(const string &s) {
        int  i = 0, j = s.size() - 1;
        while(i < j) if(s[i++] != s[j--]) return false;
        return true;
    }
    int countSubstrings(string s) {
        int n = s.size();
        int res = 0;
        for(int  i = 0; i < n; ++i) {
            for(int j = 1; j <= n - i; ++j) {                
                if(isPalindrome(s.substr(i, j))) ++res;
            }
        }
        return res;
    }
};
