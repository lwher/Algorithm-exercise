class MedianFinder {
public:
    /** initialize your data structure here. */

	priority_queue<int, vector<int>, less<int> > maxHeap;
	priority_queue<int, vector<int>, greater<int> > minHeap;

    MedianFinder() {
        // TO DO NONE
    }
    
    void addNum(int num) {
        if (maxHeap.empty() || maxHeap.top() > num) {
        	maxHeap.push(num);
        	if (maxHeap.size() - minHeap.size() > 1) {
        		minHeap.push(maxHeap.top());
        		maxHeap.pop();
        	}
        }
        else {
        	minHeap.push(num);
        	if (maxHeap.size() < minHeap.size()) {
        		maxHeap.push(minHeap.top());
        		minHeap.pop();
        	}
        }
    }
    
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
        	return (double)(maxHeap.top() + minHeap.top()) / 2;
        }
        else {
        	return maxHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */