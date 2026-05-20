class Solution {
public:
    int sumOfSquares(int n) {
        int res = 0;
        while(n) {
            int lastDigit = n % 10;
            n/=10;
            res += pow(lastDigit, 2);
        }
        return res;
    }
    bool isHappy(int n) {
        int slow = n, fast = sumOfSquares(n);
        while(slow != fast and fast != 1) {
            fast = sumOfSquares(sumOfSquares(fast));  
            slow = sumOfSquares(slow);
        }
        return fast == 1;
    }
};
