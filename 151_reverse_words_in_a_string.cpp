class Solution {
public:
    string reverseWords(string s) {
        istringstream is(s);
        string ans;
        string word;
        while(is >> word){
            ans = word + " " + ans;
        }
        return ans.size()>0? ans.substr(0,ans.size()-1):ans;
    }
};
