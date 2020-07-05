class Solution {
//1.a extention of binary search
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        if(m>n){//ensure j always >=0
            swap(m,n);
            swap(nums1,nums2);
        }
        int imin = 0;
        int imax = m;
        while (imin <= imax){//different from standard binary search, here we have "=" because imax = m is inclusive
            int i = (imin+imax)/2;
            int j = (m+n+1)/2 - i;//left part has 1 more element than right part if m+n is odd 
            if(i<m && nums2[j-1]>nums1[i]) imin = i+1; //must have condition i<m, because if i==m there's no nums1[i]
            else if(i>0 && nums1[i-1]>nums2[j]) imax = i-1;
            else{
                int max_left = 0;
                if(i == 0) max_left = nums2[j-1];
                else if(j==0) max_left = nums1[i-1];
                else max_left = max(nums1[i-1],nums2[j-1]);
                                  
                //must differentiate between odd and even
                //must put the condition statement here in case that m==0 and n==1
                if((m+n)%2 == 1) return max_left;
                           
                int min_right = 0;
                if(i == m) min_right = nums2[j];
                else if(j == n) min_right = nums1[i];
                else min_right = min(nums1[i],nums2[j]);
                
                return (max_left+min_right)/2.0; //pay attention to 2.0              
            }
        }
        return 0;
    }
};