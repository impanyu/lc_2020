class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char,int> count;
        for(char c : s){
            count[c]++;
        }
        int odds = 0;
        for(auto p : count){
            if(p.second%2 == 1){
                odds++;
                if(odds > 1) return false;
            }
        }
        return true;
    }
};
