class Solution {
public:
    
    vector<string> generateAbbreviations(string word) {
        vector<string> ans;
        dfs(ans,"",word,0);
        return ans;
    }
    //choose which point should be kept as original char
    void dfs(vector<string>& ans, string out, string& word, int start){
        if(start >= word.size()){
            ans.push_back(out);
            return;
        }
        for(int i = start; i <= word.size(); i++){
            if(i == start)
                dfs(ans,out+word[i],word,i+1);
            else if(i != word.size())
                dfs(ans,out+to_string(i-start)+word[i],word,i+1);
            else
                dfs(ans,out+to_string(i-start),word,i+1);
        }
        
    }
};
