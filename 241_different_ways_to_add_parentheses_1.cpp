class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ans;
        for(int i = 1; i < input.size(); i++){
            if(input[i] == '+' || input[i] == '-' || input[i] == '*'){
                vector<int> left = diffWaysToCompute(input.substr(0,i));
                vector<int> right = diffWaysToCompute(input.substr(i+1));
                for(int l : left){
                    for(int r : right){
                        if(input[i] == '+') ans.push_back(l+r);
                        else if(input[i] == '-') ans.push_back(l-r);
                        else ans.push_back(l*r);
                    }
                }
            }
        }
        if(ans.empty())
            ans.push_back(stoi(input));
        return ans;
            
    }
};
