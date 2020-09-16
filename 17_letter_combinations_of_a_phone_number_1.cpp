class Solution {
public:
    vector<string> letterCombinations(string digits) {
       unordered_map<char,string> phone; 
       phone['2']="abc";
       phone['3']="def";
       phone['4']="ghi";
       phone['5']="jkl";
       phone['6']="mno";
       phone['7']="pqrs";
       phone['8']="tuv";
       phone['9']="wxyz";
        
       vector<string> ans;
       string out;
       if(digits.size()>0)
           dfs(ans,out,digits,phone,0);
       return ans;      
    }
    
    void dfs(vector<string>& ans, string& out, string& digits,unordered_map<char,string>& phone, int start){
        if(start == digits.size()){
            ans.push_back(out);
            return;
        }
        for(char c: phone[digits[start]]){
            out.push_back(c);
            dfs(ans,out,digits,phone,start+1);
            out.pop_back();
        }
    }
};
