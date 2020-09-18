//bfs layer by layer
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> word_set(wordList.begin(),wordList.end());
        unordered_set<string> visited;
        queue<string> q;
        q.push(beginWord);
        int ans = 1;
        visited.insert(beginWord);
        while(!q.empty()){
            int size = q.size();
            while(size > 0){
                string word = q.front();
                q.pop();
                if(word == endWord) return ans;
                for(int i = 0; i < word.size(); i++){
                    for(char c = 'a'; c <= 'z'; c++){
                        string new_word = word.substr(0,i)+c+word.substr(i+1);
                        if(word_set.count(new_word) && !visited.count(new_word)){
                            visited.insert(new_word);
                            q.push(new_word);
                        }         
                    }
                } 
                size --;
            }
            ans++;
            
        }
        return 0;
    }
};
