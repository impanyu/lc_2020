class Solution {
//1.use a hashmap to store the map from group id to string vector
//2.copy string vectors to ans
//3.the format is very similar to 249
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> m;
        for(string s : strings){
            string key;
            for(int i = 1; i < s.size(); i++){
                key += to_string((s[i] - s[i-1] + 26)%26);
            }
            key += "0"; // in case that s has only one character
            m[key].push_back(s);
            
        }
        
        for(auto p : m){
            ans.push_back(p.second);
        }
        return ans;
    }
};
