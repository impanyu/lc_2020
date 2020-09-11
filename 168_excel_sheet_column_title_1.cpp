//"" is a string literal of type char*, can not be concatenated to string
//char can be concatenated with a string
class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        while(n>0){
            ans =  (char)((--n)%26+'A') +ans;
            n/=26;
        }
       return ans;
    }
};
