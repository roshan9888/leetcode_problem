class MedianFinder {
public:
   //brute force
    // vector<int>arr;
    // MedianFinder() {
        
    // }
    
    // void addNum(int num) {
    //     arr.push_back(num);
    // }
    
    // double findMedian() {
    //     sort(arr.begin(),arr.end());
    //     int n=arr.size();
    //     if(n%2!=0){
    //     return arr[n/2];
    //     }else{
    //         int i=n/2-1;
    //         int j=n/2;
    //         return (arr[i]+arr[j])/2.0;
    //     }
    // }

    std::priority_queue<int> lower_half; // Max-heap for the lower half of the numbers
    std::priority_queue<int, std::vector<int>, std::greater<int>> upper_half; // Min-heap for the upper half

    MedianFinder() {

    }
    
    void addNum(int num) {
        lower_half.push(num);
        
        // Balance the heaps: move the largest element from lower_half to upper_half
        upper_half.push(lower_half.top());
        lower_half.pop();

        // Ensure lower_half always has equal or more elements than upper_half
        if (lower_half.size() < upper_half.size()) {
            lower_half.push(upper_half.top());
            upper_half.pop();
        }
    }
    
    double findMedian() {
        if (lower_half.size() > upper_half.size()) {
            return lower_half.top(); // Odd number of elements, max-heap has the median
        } else {
            return (lower_half.top() + upper_half.top()) / 2.0; // Even number of elements, average of two middle elements
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */