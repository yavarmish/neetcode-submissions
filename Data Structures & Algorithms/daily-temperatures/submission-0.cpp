class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
		int n = temperatures.size();
		vector<int> nextGreaterTempDays(n, 0);
		for(int i = n - 2; i >= 0; --i) {
			int j = i + 1;
			bool  nextGreaterTempExists = true;
			while(j < n and temperatures[j] <= temperatures[i]) {
				if(nextGreaterTempDays[j] == 0) {
					nextGreaterTempExists = false;
					break;
				}
				j += nextGreaterTempDays[j];
			}
			if(nextGreaterTempExists) nextGreaterTempDays[i] = j - i;
		}
		return nextGreaterTempDays;
    }
};
