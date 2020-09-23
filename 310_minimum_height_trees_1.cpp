//bfs from edge nodes to core
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<unordered_set<int>> graph(n,unordered_set<int>());
        vector<int> ans;
        queue<int> q;    
        for(auto& edge : edges){
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }
        for(int i = 0; i < n; i++){
           if(graph[i].size() == 1) q.push(i);
        }
         
        while(n>2){
            int size = q.size();
            n -= size;
            while(size > 0){
                int cur = q.front();
                q.pop();
                int nei = *graph[cur].begin();
                graph[nei].erase(cur);
                if(graph[nei].size() == 1) q.push(nei);
                size--;
            }
        }
        
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};
