class Solution {
public:
    bool wordPattern(string pattern, string str) {
        istringstream is(str);
        vector<string> words;
        string word;
        while(is >> word){
            words.push_back(word);
        }
        if(words.size() != pattern.size())
            return false;
        
        //begin to match
        unordered_map<string, char> word_to_pattern;
        unordered_map<char,string> pattern_to_word;
        
        for(int i = 0; i < words.size(); i++){
            string word = words[i];
            if(!word_to_pattern.count(word))
                word_to_pattern[word] = pattern[i];
            if(!pattern_to_word.count(pattern[i]))
                pattern_to_word[pattern[i]] = word;
            if(word_to_pattern[word] != pattern[i] || pattern_to_word[pattern[i]] != word)
                return false;
            
        }
        return true;
        
        
    }
};
