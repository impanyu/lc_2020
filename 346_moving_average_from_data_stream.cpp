class MovingAverage {
public:
    deque<int> q; 
    int qSize;
    int sum=0;
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        qSize=size;
    }
    
    double next(int val) {
        sum+=val;
        q.push_back(val);
        if(q.size()>qSize){
            sum-=q.front();
            q.pop_front();
        }
        return (double)sum/q.size();
    }
};
