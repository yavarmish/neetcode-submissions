class TrieNode {
public:
	vector<TrieNode*> children;
	bool isEnd;

	TrieNode() {
		children.resize(26, NULL);
		isEnd = false;
	}
};
class PrefixTree {
	TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
		TrieNode* iter = root;
        for(char &ch : word) {
			if(!iter->children[ch - 'a']) {
				iter->children[ch - 'a'] = new TrieNode();
			}
			iter = iter->children[ch - 'a'];
		}
		iter->isEnd = true;
    }
    
    bool search(string word) {
		TrieNode* iter = root;
        for(auto &ch : word) {
			if(!iter->children[ch - 'a']) return false;
			iter = iter->children[ch - 'a'];
		}
		return iter->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* iter = root;
        for(auto &ch : prefix) {
			if(!iter->children[ch - 'a']) return false;
			iter = iter->children[ch - 'a'];
		}
		return true;
    }
};
