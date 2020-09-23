//two conditions: 1. no circle 2. connected
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> roots(n,-1);
        for(auto& edge : edges){
            int x = find(roots, edge[0]);
            int y = find(roots, edge[1]);
            if( x == y) return false;
            roots[x] = y;
        }  
        return edges.size() == n-1;
    }
    
    int find(vector<int>& roots, int i){
        while(roots[i] != -1) i = roots[i];
        return i;
        
    }
};
