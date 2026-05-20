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
    	string stringSize;
    	while(i<str.size() and str[i] != '#') {
    		stringSize += str[i];
    		++i;
    	}
    	++i;
    	cout<<stringSize<<"\n";
        int size = stoi(stringSize);

        string res;
    	while(size--) {
    		res += str[i];
    		++i;    		
        }
        return res;
    } 

    vector<string> decode(string &str) {
    	vector<string> ans;
        for(int i = 0; i < str.size();) {
        	string res = getIndividualString(str,i);        	
        	ans.push_back(res);
        }
        return ans;
    }
};

