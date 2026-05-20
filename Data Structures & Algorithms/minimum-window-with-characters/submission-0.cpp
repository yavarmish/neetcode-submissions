class Solution {
public:
    // returns 1 -> current > target, 0 -> current = target, -1 -> current < target
    int compareFrequencies(unordered_map<char,int> &currentFrequencies, unordered_map<char,int> &targetFrequencies) {
        bool hasGreaterFreq = false;
        for(auto &[curChar, freq] : targetFrequencies) {
            if(freq > currentFrequencies[curChar]) return -1;
            else if(freq < currentFrequencies[curChar]) hasGreaterFreq = true;
        }
        return hasGreaterFreq;        
    }
    string minWindow(string s, string t) {
        unordered_map<char, int> currentFrequencies, targetFrequencies;
        for(char &i : t) ++targetFrequencies[i];
        int i = 0, j = 0, n = s.size(), minWindowLength = n + 1;
        string res;
        while(j < n) {
            cout<<i<<" "<<j<<"\n";
            ++currentFrequencies[s[j]];
            int compRes = compareFrequencies(currentFrequencies, targetFrequencies);
            while(i <= j and compRes >= 0) {
                if(j - i + 1 < minWindowLength) {
                    minWindowLength = j - i + 1;
                    res = s.substr(i, j - i + 1);
                }
                --currentFrequencies[s[i]];
                compRes = compareFrequencies(currentFrequencies, targetFrequencies);
                ++i;
            }
            ++j;
        }
        return res;
    }
};
