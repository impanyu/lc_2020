class Solution { 
public:
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        vector<string> scales = {""," Thousand"," Million"," Billion"};
        string ans;
        int i = 0;
        //solve iteratively
        while(num>0){
            if(num%1000>0)
               ans = helper(num%1000) + scales[i]+ (ans.empty()?"":" ") +ans;
            num /= 1000;
            i++;
            
        }
        
        return ans;
    }
    
    string helper(int num){
        vector<string>lessThan20({"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine","Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"});
        vector<string>tens({"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"});
        if(num >= 100)
            return lessThan20[num/100]+" Hundred" + (num%100 == 0?"":" ") + helper(num%100);
        else if(num >= 20)
            return tens[num/10] +  (num%10 == 0?"":" ")  +lessThan20[num%10]; 
        else
            return lessThan20[num];
    }
};
