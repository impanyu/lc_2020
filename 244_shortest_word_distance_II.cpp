class WordDistance {
public:
    unordered_map<string,vector<int>> locations;
    WordDistance(vector<string>& words) {
        for(int i =0;i<words.size();i++){
            locations[words[i]].push_back(i);
        } 
    }
    
    int shortest(string word1, string word2) {
        vector<int> loc1 = locations[word1];
        vector<int> loc2 = locations[word2];
        int ans = INT_MAX;
        for(int i=0,j=0; i<loc1.size() && j<loc2.size();){
             ans = min(ans, abs(loc1[i] - loc2[j]));
             if(loc1[i] < loc2[j]) i++;
             else j++;
        }
        return ans;
        
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */
