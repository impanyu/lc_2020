//mixed bfs
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int,int>> q;
        vector<int> dirs = {-1,0,1,0,-1};
        for(int i = 0; i < rooms.size(); i++){
            for(int j = 0; j < rooms[0].size(); j++){
                if(rooms[i][j] ==0)
                    q.push(make_pair(i,j));
            }
        }
        
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            for(int i = 0; i < dirs.size()-1; i++){
        
                    int r = p.first + dirs[i];
                    int c = p.second + dirs[i+1];
                    if(r < 0 || r >= rooms.size() || c < 0 || c >= rooms[0].size() || rooms[r][c] != INT_MAX)
                        continue;
                    q.push(make_pair(r,c));
                    rooms[r][c] = rooms[p.first][p.second] + 1;
            }
        }
    }
};
