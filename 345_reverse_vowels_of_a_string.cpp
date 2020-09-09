class Solution {
private:
    bool is_vowel(char c){
        char ch = tolower(c);
        return ch == 'a' || ch == 'e' || ch == 'o' || ch == 'u' || ch == 'i';
    }
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size()-1;
        while(i<j){
            if(!is_vowel(s[i]))
                i++;
            else if(!is_vowel(s[j]))
                j--;
            else{
                swap(s[i],s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};
