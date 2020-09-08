//can prove that: for each pair of l,r, if there exists any pair of i,j, such that area(i,j)>current_max, then i>=l and j<=r
/*Suppose we get n numbers Q1, Q2, ... , Qn-1, Qn.
then we define the set Sk to contains k ( the length) continued numbers(e.g. {Q1, Q2, ... Qk} or {Q3, Q4, ... , Qk+2} ...), define Ski be the set start with Qi -- {Qi, Qi+1, ... , Qk+i-1} and then the area of Ski ( let it be A(Ski) ) is (min(Qi, Qk+i-1) * k).
Suppose we start with Ski, when we minus one item, we get two subsets S(k-1)i and S(k-1)(i+1), if Qi < Qk+i-1, we can see A(S(k-1)i)=min(Qi, Qk+i-2)(k-1)< A(Ski)=Qik, so we can determine any set contains Qi and length is smaller than k will not be the candidate that area will surpass the prior max area. So the candidates sets can only be found in the other subset S(k-1)(i+1)--{Qi+1, Qi+2, ... , Qi+k-1}. So it's reliable that we could get the max area through this path.*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_water = 0, l = 0, r = height.size()-1;
        while(l < r){
            max_water = max(max_water, (r-l)*min(height[l],height[r]));
            if(height[l] < height[r]) l++;
            else r--;
        }
        return max_water;
    }
};
