class Solution {
public:
    /* Bucket sort Time -> O(n) Space -> O(n) 
       Frequency of any number in nums lies within range 1 to n
       where n -> size of nums
    */
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> numFreq(n + 1);
        unordered_map<int, int> freq;
        for(int i = 0; i < n; ++i) {
            ++freq[nums[i]];
        }
        for(auto &[key, val] : freq) {
            numFreq[val].push_back(key);
        }
        vector<int> res;
        for(int i = n; i >= 0; --i) {
            for(int num : numFreq[i]) {
                res.push_back(num);
                if(--k == 0) {
                    return res;
                }
            }
        }
        return res;
    }
    // Time -> O(n + log(k)) Space -> O(n) [MinHeap]
    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     unordered_map<int, int> freqMap;
    //     for(auto &num : nums) ++freqMap[num];

    //     priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
    //     for(auto &[val,freq] : freqMap) {
    //         minHeap.push({freq, val});
    //         if(minHeap.size() > k) minHeap.pop();
    //     }
    //     vector<int> res;
    //     while(minHeap.size()) {
    //         res.push_back(minHeap.top().second);
    //         minHeap.pop();
    //     }
    //     return res;
    // }
};
