class Solution {
public:
    /* 
        Mantain longest subsequence
        - If    cur > max(longestSubsequence) -> add cur to longestSubsequnce
        - else  smallest number >= cur should be replaced by cur(updating a better new starting point)(greedy)
        Using upper_bound would add a new element for each duplicate creating an increasing but not strictly increasing subsequence
    */
    int lengthOfLIS(vector<int>& nums) {
        vector<int> longestSubsequence;
        for(int i = 0; i < nums.size(); ++i) {
            vector<int>::iterator it = lower_bound(longestSubsequence.begin(), longestSubsequence.end(), nums[i]);
            if(it == longestSubsequence.end()) longestSubsequence.push_back(nums[i]);
            else *it = nums[i];
        }
        return longestSubsequence.size();
    }

};
