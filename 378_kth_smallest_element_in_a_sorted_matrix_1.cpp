class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int l=matrix[0][0];
        int r=matrix[matrix.size()-1][matrix[0].size()-1];
        while(l<r){
            int mid=(l+r)/2;
            int total=0; //total number of values smaller or equal to mid        
            for(auto& row: matrix) 
                total+=upper_bound(row.begin(),row.end(), mid) - row.begin();
            if(total>=k) r=mid;
            else l=mid+1;
        }
        return l;//lower bound of k
    }
    
};
