//two read pointers, one write pointer
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int write = m+n-1;
        int p1 = m-1, p2 = n-1;
        while(p1>=0 && p2>=0)
            nums1[write--] = nums1[p1] > nums2[p2] ? nums1[p1--]:nums2[p2--];
        while(p2>=0)
            nums1[write--] = nums2[p2--];
        
    }
};
