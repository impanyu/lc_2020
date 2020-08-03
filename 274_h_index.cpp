class Solution {
public:
    int hIndex(vector<int>& citations) {
       sort(citations.begin(),citations.end(),greater<int>());
       int i =0;
       while(i<citations.size() && citations[i]>=i+1){
           i++;
       }
        return i;
    }
};
