class TrieNode{
        public:
        vector<TrieNode*> children = vector<TrieNode*>(26,nullptr);
        bool is_end = false;
    };
class WordDictionary {

public:
  
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* p = root;
        for(int i = 0; i<word.size();i++){
            if(!p->children[word[i]-'a'])
                p->children[word[i]-'a'] = new TrieNode();
            p = p->children[word[i]-'a'];
        }
        p->is_end = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchWord(word,root,0);
    }
    
    bool searchWord(string& word, TrieNode* p, int i){
        if(i == word.size()) return p -> is_end;
        if(word[i] == '.'){
            for(auto a : p->children){
                if(a && searchWord(word,a,i+1)) return true;
            }
            return false;
        }
        else{
            return p->children[word[i] - 'a'] && searchWord(word,p->children[word[i]-'a'],i+1);
        }
        
    }
 
private:
    TrieNode* root; 
    
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
