class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        queue<string> wordBfsQueue;
        wordBfsQueue.push(beginWord);
        int res = 1;
        while(wordBfsQueue.size()) {
            int k = wordBfsQueue.size();
            while(k--) {
                string curWord = wordBfsQueue.front();
                if(curWord == endWord) return res;
                wordBfsQueue.pop();
                for(int i = 0; i < curWord.size(); ++i){
                    char c = curWord[i];
                    for(int j = 0; j < 26; ++j) {
                        curWord[i] = 'a' + j;
                        if(wordSet.count(curWord)) {
                            wordBfsQueue.push(curWord);
                            wordSet.erase(curWord);
                        }
                        curWord[i] = c; 
                    }
                }
            }
            ++res;
        }
        return 0;
    }
};
