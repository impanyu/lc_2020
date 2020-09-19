class Solution {
public:
    vector<vector<int>> graph; 
    unordered_map<int,int> visited;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph = vector<vector<int>>(numCourses,vector<int>());       
        for(int i=0;i<prerequisites.size();i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int i=0;i<numCourses;i++){
          if(!can_finish_dfs(i)) return false;
        }
        return true;
    }
    //detect circle
    bool can_finish_dfs(int i){
         if(visited[i]==-1) return false;
         if(visited[i]==1) return true;
         visited[i]= -1;
         for(auto j : graph[i]){
             if(!can_finish_dfs(j)) return false;
         }
         visited[i]=1;
         return true;
    }
};
