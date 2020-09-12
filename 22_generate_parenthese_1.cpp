class Solution {
//back tracking
public:
   
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string out;
        generateP(out, ans, n,n);
        return ans;
      
    }
    void generateP(string& out, vector<string>& ans, int l, int r){
        if(l > r) return;
        if(l == 0 && r == 0) {
            ans.push_back(out);
            return;
        }
        if(l>0){
            out.push_back('(');
            generateP(out,ans,l-1,r);
            out.pop_back();
        }
        if(r>0){
            out.push_back(')');
            generateP(out,ans,l,r-1);
            out.pop_back();
        }
        
    } 
};
