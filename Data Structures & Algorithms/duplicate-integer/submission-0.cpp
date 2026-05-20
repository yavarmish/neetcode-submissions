class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> numsSet;
        for(auto &num : nums) {
            if(numsSet.count(num)) return true;
            numsSet.insert(num);
        }
        return false;
    }
};