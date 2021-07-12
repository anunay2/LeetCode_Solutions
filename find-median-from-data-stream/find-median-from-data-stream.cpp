class MedianFinder {
public:
    multiset<int> arr;
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        arr.insert(num);
    }
    
    double findMedian() {
        int n = arr.size();
        auto itr1 = arr.begin();
        advance(itr1,n/2);
        if(n%2)
            return *itr1;
        else{
            auto itr2 = itr1 --;
            return ((*itr1 + *itr2)*1.0)/2.0;
        }
        return -1;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */