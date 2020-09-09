//every time we need s.size()-1, we should first case it to int, for s.size() is an unsigned int 
class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> ans;
        for(int i = 0;i < int(s.size())-1; i++){
            if(s[i] == '+' && s[i+1] == '+'){
                string new_s = s;
                new_s[i] = '-';
                new_s[i+1] = '-';
                ans.push_back(new_s);
            }
                
        }
        return ans;
    }
};
