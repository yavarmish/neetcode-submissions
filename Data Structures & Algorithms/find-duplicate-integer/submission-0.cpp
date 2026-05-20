class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> uniqueNums;
        for(auto &num : nums) {
            if(uniqueNums.count(num)) return num;
            uniqueNums.insert(num);
        }
        return -1;
    }
};
