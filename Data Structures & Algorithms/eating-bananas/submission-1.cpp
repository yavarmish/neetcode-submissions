#define ll long long
class Solution {
public:
    // Time : O(log(max_element(piles))) Space: O(1)
    int minEatingSpeed(vector<int>& piles, int h) {
        ll lowestSpeed = 1, highestSpeed = *max_element(piles.begin(), piles.end()), curSpeed, minSpeed = highestSpeed; 
        while(lowestSpeed <= highestSpeed) {
            curSpeed = lowestSpeed + (highestSpeed - lowestSpeed) / 2;
            ll timeTaken = 0;
            for(auto &i : piles) timeTaken += ceil(1.0 * i / curSpeed);
            if(timeTaken <= h) {
                minSpeed = curSpeed;
                highestSpeed = curSpeed - 1;
            }
            else {
                lowestSpeed = curSpeed + 1;
            }
        }
        return minSpeed;
    }   
};
