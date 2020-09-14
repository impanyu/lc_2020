class Solution {
public:
   vector<string> findRepeatedDnaSequences(string s) {
       unordered_map<string,int> count;
       vector<string> ans;
       //cast to int
       for(int i = 0;i <= (int)(s.size()-10); i++){
           count[s.substr(i,10)]++;
           if(count[s.substr(i,10)] ==2) // only add once for each sub-sequence
               ans.push_back(s.substr(i,10));
       }
       return ans;

  } 
};

