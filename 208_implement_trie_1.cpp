class TrieNode {

    public:
    vector<TrieNode*> children=vector<TrieNode*>(26,nullptr);
    bool is_end=false;   
};

class Trie {
    private:
        TrieNode* root;
    public:
        Trie() {
            root = new TrieNode();
        }
  
   
        // Inserts a word into the trie.
       void insert(string word) {
         TrieNode* p = root;
         for(int i=0;i<word.size();i++){
             if(!p->children[word[i]-'a'])
                 p->children[word[i]-'a'] = new TrieNode();
              p=p->children[word[i]-'a'];
         }
         p->is_end=true;
      }     
        // Returns if the word is in the trie.
      bool search(string key) {
         TrieNode* p = root;
         for(int i=0;i<key.size();i++){
             if(!p->children[key[i]-'a']) return false;
              p=p->children[key[i]-'a'];
         }
         return p->is_end;
        }   
        // Returns if there is any word in the trie
        // that starts with the given prefix.
        bool startsWith(string prefix) {
         TrieNode* p = root;
         for(int i=0;i<prefix.size();i++){
             if(!p->children[prefix[i]-'a']) return false;
              p=p->children[prefix[i]-'a'];
         }
         return true;
        }
};
