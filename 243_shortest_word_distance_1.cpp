class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int ans = words.size();
        int p1=-1, p2=-1;
        for(int i = 0; i<words.size();i++){
            if(words[i] == word1) 
                p1 = i;
            if(words[i] == word2)
                p2 = i;
            
            if(p1 >=0 && p2>=0)
                ans = min(ans,abs(p1-p2));
        }
        return ans;
    }
};
