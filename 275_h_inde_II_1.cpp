//0 0 0 0 1 1 1 1
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size() == 0) return 0;
        int l = 0, r = citations.size();
        while(l<r){
            int mid = (l+r)/2;
            if(citations[mid] >= citations.size()-mid) r =mid;
            else l = mid+1 ;
        }
        return  citations.size()-l;
    }
};
