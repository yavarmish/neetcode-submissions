class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c = 0;
        for(int i = digits.size() - 1; i >= 0; --i) {
            if(digits[i] < 9) {
                digits[i] += 1;
                return digits;
            }
            else {
                digits[i] = 0;
                c = 1;
            } 
        }
        if(c) {
            digits.insert(digits.begin(), 1);
            return digits;
        }
    }
};
