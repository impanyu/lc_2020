//this method has no overflow trouble, but pay attention to the precautions made(the first line).  (x!=0 && x%10==0) is necessary to prevent the last digit is 0.
//compare to 7 reverse integer
class Solution {
public:
    bool isPalindrome(int x) {
        if(x == 0) return true;
        if(x < 0 || x%10 == 0) return false;
        int reverted = 0;
        while(reverted < x){
            reverted = reverted*10 + x%10;
            x /= 10;
        }
        return reverted == x || reverted/10 == x;
    }
};
