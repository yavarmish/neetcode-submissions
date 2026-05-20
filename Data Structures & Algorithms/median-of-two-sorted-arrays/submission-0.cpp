class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /* 
                |
            1 2 3 4 5
                |    
            1 2 3 4 5 6 7 8
                        |
            1 1 2 2 3 3 4 4 5 5 6 7 8

            total: 13 smaller: 5 larger: 8 contrSmaller: 3 contrLarger: 3
            - Part before meadian would comprise of some elements from nums1 and nums2
            - If contribution of smaller array is known, we can determine the contribution of other part(total / 2 - contrSmaller)
              hence BS on smaller array is sufficient
            - We'd know that we reached the median if nums1[smallerMidIdx] <= nums2[largerMidIdx + 1] and nums2[largerMidIdx] <= nums1[smallerMidIdx + 1]
            - if total is odd result would be min(nums1[smallerMidIdx + 1], nums[largerMidIdx + 1]) 
              otherwise max(nums1[smallerMidIdx], nums2[largerMidIdx]) + min(nums1[smallerMidIdx + 1], nums2[largerMidIdx + 1]) / 2      

            Implementation in terms of nextToSmallerMidIdx, nextToLargerMidIdx avoids edge cases in C++(negative indices handled in python)  
        */    
        if(nums1.size() > nums2.size()) swap(nums1, nums2);        
        int n = nums1.size(), m = nums2.size(), left = 0, right = n - 1, total = n + m;
        int nextToSmallerMidIdx, nextToLargerMidIdx, smallerMid, nextToSmallerMid, largerMid, nextToLargerMid;
        while(1) {
            nextToSmallerMidIdx = left + (right - left) / 2;
            nextToLargerMidIdx = total / 2 - nextToSmallerMidIdx;

            smallerMid = nextToSmallerMidIdx > 0 ? nums1[nextToSmallerMidIdx - 1] : INT_MIN;
            largerMid = nextToLargerMidIdx > 0 ? nums2[nextToLargerMidIdx - 1] : INT_MIN; 
            nextToSmallerMid = nextToSmallerMidIdx < n ? nums1[nextToSmallerMidIdx] : INT_MAX;
            nextToLargerMid = nextToLargerMidIdx < m ? nums2[nextToLargerMidIdx] : INT_MAX;
            
            if(smallerMid <= nextToLargerMid and  largerMid <= nextToSmallerMid) {
                if(total & 1) 
                    return min(nextToSmallerMid, nextToLargerMid);
                else 
                    return (double) 1.0*(max(smallerMid, largerMid) + min(nextToSmallerMid, nextToLargerMid)) / 2;
            }
            else if(smallerMid > nextToLargerMid) right = nextToSmallerMidIdx - 1;
            else left = nextToSmallerMidIdx + 1;             
        }
        return -1;
    }
};
