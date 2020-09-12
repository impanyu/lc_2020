class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size()-1;
        while(i<j){
            char a = tolower(s[i]);
            char b = tolower(s[j]);
            if(a == b){ 
                i++;
                j--;
            }
            else if(!isalnum(a))
                i++;
            else if(!isalnum(b))
                j--;
            else
                return false;
            
            
        }
        return true;
    }
};
