class SummaryRanges {
private:
    vector<vector<int>> intervals; 
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    //exactly the same as 57_insert_interval
    //assume intervals is sorted
    void addNum(int val) {
        vector<vector<int>> ans;
        vector<int> new_interval(2,val);
        int pos = 0;
        for(auto interval : intervals){
            if(interval[1] +1 < val){
                ans.push_back(interval);
                pos++;
            }
            else if(interval[0]-1> val)
                ans.push_back(interval);
            else{
                new_interval[1] = max(new_interval[1], interval[1]);
                new_interval[0] = min(new_interval[0], interval[0]);
            }
        }
        ans.insert(ans.begin()+pos, new_interval);
        
        
        intervals = ans;
    }
    
    vector<vector<int>> getIntervals() {
        return intervals;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
