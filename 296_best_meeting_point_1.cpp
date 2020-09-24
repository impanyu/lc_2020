class Solution {
private:
    int min_distance(vector<int> points, int mid){
        int ans = 0;
        for(int point : points){
            ans += abs(point - mid);
        }
        return ans;
    }
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> rows;
        vector<int> cols;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        int row_mid = rows[rows.size()/2];
        sort(cols.begin(),cols.end());
        int col_mid = cols[cols.size()/2];
        return min_distance(rows,row_mid)+min_distance(cols,col_mid); 
    }
};
