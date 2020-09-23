class Solution {
public:
   bool exist(vector<vector<char>>& board, string word) {
    for (unsigned int i = 0; i < board.size(); i++) 
        for (unsigned int j = 0; j < board[0].size(); j++) 
            if (dfs(board, i, j, word))
                return true;
    return false;
}

bool dfs(vector<vector<char>>& board, int i, int j, string& word) {
    if (!word.size())
        return true;
    if (i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j] != word[0])  
        return false;
    char c = board[i][j];
    board[i][j] = '*';
    string s = word.substr(1);
    bool ret = dfs(board, i-1, j, s) || dfs(board, i+1, j, s) || dfs(board, i, j-1, s) || dfs(board, i, j+1, s);
    board[i][j] = c;
    return ret;
  }       
};



//method 2: accumulate s 
class Solution {
public:
   bool exist(vector<vector<char>>& board, string word) {
       string s;
       vector<int> dirs = {0,1,0,-1,0};
       for (unsigned int i = 0; i < board.size(); i++) 
           for (unsigned int j = 0; j < board[0].size(); j++) {
               s.push_back(board[i][j]);
               board[i][j] = '*';
               if (dfs(board, word, s,dirs, i, j))
                   return true;
              board[i][j] = s.back();
              s.pop_back();
           }
       return false;
}

bool dfs(vector<vector<char>>& board,string& word, string& s, vector<int>& dirs, int i, int j ) {
    if (s != word.substr(0,s.size()))
        return false;
    if(s == word)
        return true;
    
    for(int k = 0; k < dirs.size()-1; k++){
        int new_i = i+dirs[k];
        int new_j = j+dirs[k+1];
        if (new_i<0 || new_i>=board.size() || new_j<0 || new_j>=board[0].size() || board[new_i][new_j] == '*')  
            continue;
        s.push_back(board[new_i][new_j]);
        board[new_i][new_j] = '*';
        if(dfs(board,word,s,dirs,new_i,new_j))
            return true;
        board[new_i][new_j] = s.back();
        s.pop_back();
    }
    return false;
  }       
};
