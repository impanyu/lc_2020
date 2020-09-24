class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> ans(length+1,0);
        for(auto& update : updates){
            ans[update[0]] += update[2];
            ans[update[1]+1] += -update[2];
        }
        for(int i = 1; i < length; i++){
            ans[i] += ans[i-1];
        }
    
        return vector<int>(ans.begin(),ans.end()-1);
    }
};
