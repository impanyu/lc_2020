class Solution {
//1.recursive solution
//2.in each recursion, using two pointer propelled by faster one
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string prev = countAndSay(n-1);
        string ans;
        int i = 0, j = 0;
        for(; j <= prev.size(); j++){
            if(j == prev.size() || prev[j] != prev[i]){
                ans += to_string(j-i);
                ans += prev[i];
                i = j;
            }
        }
        return ans;
    }
};
