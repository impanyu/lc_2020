//the same method as 240
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0) return false;
        int i=0;
        int j=matrix[0].size()-1;
        while(i<matrix.size() && j>=0){
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]>target) j--;
            else i++;
        }
        return false;
    }
};


//1-d binary search method only applied to this problem
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) return false;
        int l = 0, r = matrix.size()*matrix[0].size();
        while(l < r){
            int mid = l + (r-l)/2;
            int row = mid / matrix[0].size();
            int col = mid % matrix[0].size();
            if(matrix[row][col] >= target) 
                r = mid;
            else
                l = mid + 1;
            
        }
        
        
        return l != matrix.size()*matrix[0].size() && matrix[l/matrix[0].size()][l%matrix[0].size()] == target;
    }
};
