class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freqS(26, 0), freqT(26, 0);
        for(auto &ch : s) ++freqS[ch - 'a'];
        for(auto &ch : t) ++freqT[ch - 'a'];
        for(int i = 0; i < 26; ++i) if(freqS[i] != freqT[i]) return false;
        return true;
    }
};
