class Solution {
public:
    int calculate(string s) {
        int ans = 0;
        char sign = '+';
        stack<int> nums;
        for(int i = 0; i < s.size(); i++){
            if(s[i] >= '0' && s[i] <= '9'){
                int num = 0;
                while(s[i] >= '0' && s[i] <= '9'){
                    num *= 10;
                    num += s[i]-'0';
                    i++;
                }
                i--;
                
                if(sign == '+')
                    nums.push(num);
                else if(sign == '-')
                    nums.push(-num);
                else{
                    int tmp = sign == '*' ? nums.top()*num : nums.top()/num;
                    nums.pop();
                    nums.push(tmp);
                }
                
            }
            else if(s[i] != ' ')
                sign = s[i];
        }
        while(!nums.empty()){
            ans +=nums.top();
            nums.pop();
        }
        return ans;
    }
};
