class TimeMap {
public:
	// Binary Search : Time for get O(log n) Space O(n * m) n -> set calls m 
	unordered_map<string, vector<pair<int, string>>> keyTimeStampValueMapping;
    void set(string key, string value, int timestamp) {
        keyTimeStampValueMapping[key].push_back( {timestamp, value} );
    }    
	static bool cmp(int val, const pair<int, string>& p) {
		return p.first > val;
	}
    string get(string key, int timestamp) {
        vector<pair<int, string>> TimeValue = keyTimeStampValueMapping[key];
		int upperBoundIdx = upper_bound(TimeValue.begin(), TimeValue.end(), timestamp, cmp) - TimeValue.begin();
        cout<<upperBoundIdx<<"\n";
		if(upperBoundIdx == 0) return "";
		else return TimeValue[upperBoundIdx - 1].second;
    }
};
