class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans(A.size(),vector<int>(B[0].size()));
        vector<vector<int>> v(A.size(),vector<int>());
        for(int i = 0; i < A.size(); i++){
            for(int j = 0; j < A[0].size(); j++){
                if(A[i][j] !=0)
                    v[i].push_back(j);
            }
        }
        
        for(int i = 0; i < A.size(); i++){
            for(int k = 0; k < v[i].size(); k++){
                for(int j = 0; j < B[0].size(); j++){
                    ans[i][j] += A[i][v[i][k]]*B[v[i][k]][j];
                }
            }
        }
          
        return ans;
    }
};
