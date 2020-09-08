//basic idea, for each pos, we need to find the min of (left max and right max) of both sides(inclusive).
//we can solve the problem in one pass using two pointers
class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int rain = 0, lmax = 0, rmax = 0;
        while(i<j){
            if(height[i]<height[j]){
                lmax = max(lmax, height[i]);
                rain += lmax - height[i];
                i++;
            }
            else{
                rmax = max(rmax, height[j]);
                rain += rmax - height[j];
                j--;
            }
        }
        return rain;
        
    }
};
