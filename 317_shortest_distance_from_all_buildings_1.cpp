class Solution {
public:
   int shortestDistance(vector<vector<int>> grid) {
     int m=grid.size(), n=grid[0].size();
     auto total=grid;
     int dirs[]={0,1,0,-1,0};
     int starting_id=0;
     int ans;
     for(int i=0;i<m;i++){
         for(int j=0;j<n;j++){
             
             if(grid[i][j]!=1) continue;
             auto dist=grid;
             ans=-1;
             queue<pair<int,int>> q;
             q.push(make_pair(i,j));
             while(!q.empty()){
                 auto cur=q.front();
                 q.pop();
                 for(int k=0;k<4;k++){
                     int ni=cur.first+dirs[k];
                     int nj=cur.second+dirs[k+1];
                     if(ni>=0 && ni<m && nj>=0 && nj<n && grid[ni][nj]==starting_id){
                          
                          grid[ni][nj]--;
                          dist[ni][nj]=dist[cur.first][cur.second]+1;
                          total[ni][nj]+=dist[ni][nj]-1;
                          q.push(make_pair(ni,nj));
                         
                          if(ans<0 || total[ni][nj]<ans)
                              ans=total[ni][nj];                         
                     } 
                 }    
             }
             starting_id--;    
         }
     }
     return ans;
  }
};
