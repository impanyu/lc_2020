//bfs
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> ins(numCourses,0);
        queue<int> q;
        for(auto& pre : prerequisites){
            graph[pre[1]].push_back(pre[0]);
            ins[pre[0]]++;
        }
        for(int i = 0; i < numCourses; i++){
            if(ins[i] == 0)
                q.push(i);
        }
        
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            ans.push_back(cur);
            for(int i : graph[cur]){
                if(--ins[i] == 0)
                    q.push(i);
            }
        }
        
        return ans.size() == numCourses ? ans: vector<int>();
    }
};
