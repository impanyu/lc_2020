//string to int: stoi or istringstream
//int to string: to_string or ostringstream
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans;
        vector<string> num_strings;
        
        for(int num : nums)
            num_strings.push_back(to_string(num));
        
        sort(num_strings.begin(),num_strings.end(),
            [](string a, string b){
                 return a+b > b+a; });
        
        if(num_strings[0] == "0")
            return "0";
        
        for(string n : num_strings)
            ans += n;
               
        return ans;
    }
};
