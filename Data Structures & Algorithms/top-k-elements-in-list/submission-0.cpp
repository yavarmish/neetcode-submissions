class Solution {
public:
    // Time ->. O(n + log(k)) Space -> O(n)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for(auto &num : nums) ++freqMap[num];

        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        for(auto &[val,freq] : freqMap) {
            minHeap.push({freq, val});
            if(minHeap.size() > k) minHeap.pop();
        }
        vector<int> res;
        while(minHeap.size()) {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return res;
    }
};
