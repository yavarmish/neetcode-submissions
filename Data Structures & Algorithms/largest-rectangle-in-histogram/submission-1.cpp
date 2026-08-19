class Solution {
public:
    /*
        Idea -> Each bar can be considered as the limiting bar for maxArea at a time, max of them would be our answer
        Bruteforce -> O(n^2)

        Segment Tree -> O(n*log(n))
        For each range(starting with the entire array) we find the min bar 
        And compute max of these for our answe:
        area_with_min = heights[minIndex] * (R - L + 1)
        area_left = solve(L, minIndex - 1)
        area_right = solve(minIndex + 1, R)

        Monotonic Stack of indexes -> O(n)
        We can use a monotonically increasing stack 
        When we encounter an element less than the top, we've found the right boundary for the stack item
        And after we've popped it, the element at the top of stack gives us the left boundary
        i.e. width = i - stack.top() - 1 (Right Boundary - LeftBoundary - 1)
        [Edge case 1 -> If after popping no elements are left -> width = i i.e. only right boundary]

        [Edge case 2 -> If we reach the end and we still have some elements in the stack we'd have to repeat the process of popping once more for the remaining elements]

        [7,1,7,2,2,4] 
        Nums      Idx Stack
        [7]         [0]          res -> 0  i -> 0
        [1]         [1]          res -> 7  i -> 1
        [1,7]       [1,2]        res -> 7  i -> 2
        [1,2]       [1,3]        res -> 7  i -> 3
        [1,2]       [1,3]        res -> 7  i -> 4
        [1,2,4]     [1,4,5]      res -> 7, i -> 5


        [1,2]       [1,4]        res -> 7, i -> 6
        [1]         [1]          res -> height(2) * width(6 - 1 - 1) -> 8
        []          []           res -> 8


    */
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int res = 0;

        stack<int> heightIdx;
        for(int i = 0; i <= n; ++i) {
            while(heightIdx.size() and ((i == n) || heights[heightIdx.top()] >= heights[i])) {
                int height = heights[heightIdx.top()];
                heightIdx.pop();
                int width = heightIdx.empty() ? i : i - heightIdx.top() - 1;
                res = max(res, height * width);
            }
            heightIdx.push(i);
        }
        return res;
    }
};
