class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ans;
        for(string s : strs){
            ans = ans.append(to_string(s.size())).append("/").append(s);
        }
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans;
        int i;
        while(i<s.size()){
            int j = s.find("/",i);
            int length = stoi(s.substr(i,j-i));
            ans.push_back(s.substr(j+1,length));
            i = j+1+length;
        }
        
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
