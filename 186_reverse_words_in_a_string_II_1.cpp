//reverse the whole string first
//then reverse each word
class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(),s.end());
        int i = 0;
        for(int j = 0;j <= s.size(); j++){
            if(j == s.size() || s[j] == ' '){
                reverse(s.begin()+i, s.begin()+j);
                i = j+1;
            }
        }
    }
};
