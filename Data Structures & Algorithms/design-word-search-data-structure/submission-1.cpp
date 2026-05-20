class TrieNode {
public:
    vector<TrieNode*> childNodes;
    bool isEnd;
    TrieNode() {
        childNodes.resize(26, NULL);
        isEnd = false;
    }
};

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* iter = root;
        for(char &ch : word) {
            if(!iter->childNodes[ch - 'a']) 
                iter->childNodes[ch - 'a'] = new TrieNode();
            iter = iter->childNodes[ch - 'a'];
        }
        iter->isEnd = true;
    }
    bool recursiveSearch(string &word, int i, TrieNode* iter) {
        if(i == word.size() and iter and iter->isEnd) return true;
        if(!iter) return false;
        if(word[i] != '.' and !iter->childNodes[word[i] - 'a']) return false;

        if(word[i] == '.') {
            bool res = false;
            for(TrieNode* child : iter->childNodes) {
                if(res) break;
                res |= recursiveSearch(word, i + 1, child);
            }
            return res;
        }
        else {
            if(iter->childNodes[word[i] - 'a']) return recursiveSearch(word, i + 1, iter->childNodes[word[i] - 'a']);
            else return false;
        }
    }

    bool search(string word) {
        TrieNode* iter = root;
        return recursiveSearch(word, 0, iter);   
    }
};
