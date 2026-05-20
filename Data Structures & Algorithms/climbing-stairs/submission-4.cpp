class Solution {
public:    
    // Math based Time O(logn) Space O(1)
    int climbStairs(int n) {
        ++n;
        return (1 / sqrt(5)) * (pow((1 + sqrt(5)) / 2, n) - pow((1 - sqrt(5)) / 2, n));
    }
};
