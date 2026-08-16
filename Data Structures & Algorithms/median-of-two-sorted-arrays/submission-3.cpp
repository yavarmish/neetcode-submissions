class Solution {
public:
    /*
        nums1 = [1, 5, 7, 13, 16]
        nums2 = [1, 2, 3, 4, 6]
        final = [1,1,2,3,[4,5],6,7,13,16]

        Idea: Find number of contributing elements from shorter array

        Valid -> l1 <= r2 and l2 <= r1
        Invalid [l2 ? r2]
        [1]        [5,7,13,16] 
        [1,2,3,4,6][]
        -> 1 < INT_MAX(always true) and 6 > 5(invalid)
        -> Search right

        Valid
        [1,5]    [7,13,16] 
        [1,2,3,4][6]
        -> 5 < 6 and 4 < 7
        -> Median = max(l1, l2) + min(r1, r2) / 2.0

        Invalid [l1 > r2]
        [1,5,7][13,16] 
        [1,2,3][4,6]
        -> 7 > 4(invalid) and 3 < 13
        -> serch left

        https://www.youtube.com/watch?v=F9c7LpRZWVQ
        Time -> O(log(min(n, m))) Space -> O(1)
    */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Perform binary search on the smaller array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int n1 = nums1.size() , n2 = nums2.size();
        int low = 0, high = n1;
        // Size of the left half. Adding 1 handles both even and odd total lengths.
        int leftPartitionSize = (n1 + n2 + 1) / 2;
        
        while (low <= high) {
            // mid1 is the number of contributing elements from nums1
            int mid1 = low + (high - low) / 2;
            // mid2 is the remaining elements needed from nums2 for the left partition
            int mid2 = leftPartitionSize - mid1;
            
            // Determine l1, r1, l2, r2. INT_MIN/INT_MAX for out-of-bounds safety.
            int l1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
            int r1 = (mid1 == n1) ? INT_MAX : nums1[mid1];        
            int l2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
            int r2 = (mid2 == n2) ? INT_MAX : nums2[mid2];
            
            // Condition 1: Valid Partition
            if (l1 <= r2 && l2 <= r1) {
                if ((n1 + n2) % 2 == 0) 
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                else 
                    return max(l1, l2);
            }
            // Condition 2: Invalid (l1 > r2) -> search left
            else if (l1 > r2) {
                high = mid1 - 1;
            }
            // Condition 3: Invalid (l2 > r1) -> search right
            else {
                low = mid1 + 1;
            }
        }
        
        return 0;
    }
};
