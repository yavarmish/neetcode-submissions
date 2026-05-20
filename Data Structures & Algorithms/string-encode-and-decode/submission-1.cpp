/*
	Design an algorithm to encode a list of strings to a single string. The encoded string is then decoded back to the original list of strings.
	Implement encode and decode
	1 <= strs.length < 200
	0 <= strs[i].length < 200
	strs[i] contains only UTF-8 characters.
*/

class Solution {
public:
	// Mataining size while encoding allows decoding uniquely
    string encode(vector<string> &strs) {
        string encodedString;
        for(string& s : strs) {
        	int size = s.size();
        	encodedString += to_string(size) + "#" + s;
        }
        return encodedString;
    }

    string getIndividualString(string &str,int &i) {
    	size_t delimPos = str.find('#',i);
    	string stringSize = str.substr(i, delimPos - i);    
    	int size = stoi(stringSize);
    	i = delimPos + 1;
        string res = str.substr(i, size);
        i += size;
        return res;
    } 

    vector<string> decode(string &str) {
    	vector<string> ans;
        for(int i = 0; i < str.size(); ) {
        	string res = getIndividualString(str,i);        	
        	ans.push_back(res);
        }
        return ans;
    }

    // Can also mantain a fixed length for each string size(for example first 4 characters) instead of using a delimeter('#')
};

