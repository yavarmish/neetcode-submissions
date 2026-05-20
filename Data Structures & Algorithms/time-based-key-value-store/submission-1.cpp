class TimeMap {
public:
	// Map with hint : Time for get O(log n) for set O(1) if using hint Space: 
	unordered_map<string, map<int, string>> keyTimeStampValueMapping;
    void set(string key, string value, int timestamp) {
		map<int, string>::iterator hint = keyTimeStampValueMapping[key].begin();
        keyTimeStampValueMapping[key].insert( hint, {timestamp, value} );
    }    
    string get(string key, int timestamp) {
        map<int, string> TimeValue = keyTimeStampValueMapping[key];
        map<int, string>::iterator it = TimeValue.upper_bound(timestamp);
        return it == TimeValue.begin() ? "" : prev(it)->second;
    }
	
	// Binary Search : Time for get O(log n) Space O(n * m) n -> set calls m -> get calls
	// unordered_map<string, vector<pair<int, string>>> keyTimeStampValueMapping;
    // void set(string key, string value, int timestamp) {
    //     keyTimeStampValueMapping[key].push_back( {timestamp, value} );
    // }    
	// static bool cmp(int val, const pair<int, string>& p) {t
	// 	return p.first > val;
	// }
    // string get(string key, int timestamp) {
    //     vector<pair<int, string>> TimeValue = keyTimeStampValueMapping[key];
	// 	int upperBoundIdx = upper_bound(TimeValue.begin(), TimeValue.end(), timestamp, cmp) - TimeValue.begin();
 	// 	if(upperBoundIdx == 0) return "";
	// 	else return TimeValue[upperBoundIdx - 1].second;
    // }
};
