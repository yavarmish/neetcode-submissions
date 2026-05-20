class PrefixTreeNode {
public:
	vector<PrefixTreeNode*> childNodes;
	bool isEnd;

	PrefixTreeNode() {
		childNodes.resize(26, NULL);
		isEnd = false;
	}
};
class PrefixTree {
	PrefixTreeNode* root;
public:
    PrefixTree() {
        root = new PrefixTreeNode();
    }
    
    void insert(string word) {
		PrefixTreeNode* iter = root;
        for(char &ch : word) {
			if(!iter->childNodes[ch - 'a']) {
				iter->childNodes[ch - 'a'] = new PrefixTreeNode();
			}
			iter = iter->childNodes[ch - 'a'];
		}
		iter->isEnd = true;
    }
    
    bool search(string word) {
		PrefixTreeNode* iter = root;
        for(auto &ch : word) {
			if(!iter->childNodes[ch - 'a']) return false;
			iter = iter->childNodes[ch - 'a'];
		}
		return iter->isEnd;
    }
    
    bool startsWith(string prefix) {
        PrefixTreeNode* iter = root;
        for(auto &ch : prefix) {
			if(!iter->childNodes[ch - 'a']) return false;
			iter = iter->childNodes[ch - 'a'];
		}
		return true;
    }
};
