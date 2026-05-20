class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        else if(n == 1) return x;
        else if(n < 0) {
            x = 1 / x;
            n *= -1;
        }        
        double evenPow = pow(myPow(x, n / 2 ), 2);
        if(n & 1) {
            return x * evenPow;
        }
        else return evenPow;
    }
};
