class Solution {
public:
    int jump(vector<int>& nums) {
        /* 
            BFS(Greedy) -> Each level considers the farthest we can reach from that level
            Time -> O(n) Space -> O(1)
        */
        int res = 0, l = 0, r = 0;
        while(r < nums.size() - 1) {
            int farthest = 0;
            for(int i = l; i <= r; ++i) {
                farthest = max(farthest, i + nums[i]);
            }
            // next level
            l = r + 1;
            r = farthest;
            ++res;
        }
        return res;
    }
};
