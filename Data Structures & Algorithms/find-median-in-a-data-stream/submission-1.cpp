class MedianFinder {
public:
    /*
        Idea: Mantain 2 heaps[smallerHalf(maxHeap), largerHalf(minHeap)]
        Goal: Ensure balanced size and numbers in smallerHalf == largerHalf(or + 1)
        Median = Top of bigger heap(odd) or average of both tops(even)
    */
    priority_queue<int> smallHeap;
    priority_queue<int, vector<int>, greater<int>> largeHeap;

    void addNum(int num) {
        // Push to largeHeap(can also do the same bounce for smallHeap)
        smallHeap.push(num);
        largeHeap.push(smallHeap.top());
        smallHeap.pop();

        // smallHeap is always >= largeHeap in size
        if(largeHeap.size() > smallHeap.size()) {
            smallHeap.push(largeHeap.top());
            largeHeap.pop();
        }
    }
    
    double findMedian() {
        return smallHeap.size() > largeHeap.size() ?
        smallHeap.top(): (smallHeap.top() + largeHeap.top()) / 2.0;
    }
};
