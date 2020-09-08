class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> ans;
        unordered_map<int,int> last_index;
        int i = 0, j = 0, split = 0;
        for(; i < S.length(); i++)
            last_index[S[i]] = max(i, last_index[S[i]]);
        i = 0;
        for(;j < S.length(); j++){
            split = max(split,last_index[S[j]]);
            if (split == j){
                ans.push_back(j-i+1);
                i = j+1;
            }
            
        }
        return ans;
    }
};
