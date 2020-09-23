class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> roots(n,-1);
        int ans = 0;
        for(auto& edge : edges){
            int x = find(roots, edge[0]);
            int y = find(roots,edge[1]);
            if(x != y) roots[x] = y;// we use -1 to indicate root, so avoid case x == y
        }
        for(int root : roots){
            if(root == -1)
                ans++;
        }
        return ans;
    }
    
    int find(vector<int>& roots, int i){
        while(roots[i] != -1) i = roots[i];
        return i;
    }
};
