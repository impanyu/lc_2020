//compared with divide and conquer, dfs(back_tracking) is better.
//because the former one is to receive partial results from lower level, and the latter one passes references to partial results to lower level.
class Solution {
private:
    bool is_palindrome(string s){
        for(int i = 0;i<s.size();i++){
            if(s[i] != s[s.size()-1-i])
                return false;
        }
        return true;
    }
    void dfs(string s, int start, vector<string> &out, vector<vector<string>> & ans){
        if(start == s.size()){
            ans.push_back(out);
            return;
        }
         for(int i = start; i < s.size(); i++){
            if(is_palindrome(s.substr(start,i-start+1))){
                out.push_back(s.substr(start,i-start+1));
                dfs(s,i+1,out,ans);
                out.pop_back();           
            }
                
        }
            
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> out;
        dfs(s,0,out,ans);
        return ans;
    }
};
