class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> s_map;
        for(char c : s)
            s_map[c]++;
        for(char c : t){
            s_map[c]--;
            if(s_map[c]<0) 
                return c;
        }
        
        return 'a';
    }
};


//method2: bit_manipulation
class Solution {
public:
    char findTheDifference(string s, string t) {
        char ch = 0;
        for(char c : s)
            ch ^= c;
        for(char c : t)
            ch ^=c;
        return ch;
    }
};
