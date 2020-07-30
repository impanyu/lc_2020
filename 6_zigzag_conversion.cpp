class Solution {
public:
    //each row:
    //T 0
    //T-2 2
    //T-4 4
    //T-6 6
    //...
    //0 T
    string convert(string s, int numRows) {
        if(numRows ==1) return s;
        int T = numRows*2-2;
        string ans = "";
        //i denotes row
        for(int i=0;i<numRows;i++){
            //j denotes the relative index in each row
            for(int j=0;i+j<s.size();j+=T){
                ans+=s[i+j];
                //i+j+(T-2i) = j+T-i
                if(i>0 && i<numRows-1 && j+T-i<s.size())
                    ans+=s[j+T-i];
            }
        }
        return ans;
    }
};
