class Solution {
public:
    /*
        Recursion
        Permute the following elements for each element then try inserting it at all the possible positions in each permuatation
        Time O(n! * n^2) Aux. Space O(n! * n)        
    */
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty()) return {{}};
        vector<int> followingNums(nums.begin() + 1, nums.end());
        vector<vector<int>> followingPermuations = permute(followingNums);
        vector<vector<int>> res;
        for(auto &followingPermuation : followingPermuations) {
            for(int i = 0; i <= followingPermuation.size(); ++i) {
                vector<int> followingPermuationCopy = followingPermuation;
                followingPermuationCopy.insert(followingPermuationCopy.begin() + i, nums[0]);
                res.push_back(followingPermuationCopy);
            }   
        }
        return res;
    }

};
