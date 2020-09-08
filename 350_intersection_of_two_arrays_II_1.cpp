class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int> map1;
        for(int num1 : nums1) 
            map1[num1]++;
        for(int num2 : nums2){
            if(map1[num2] > 0){
                ans.push_back(num2);
                map1[num2]--;
            }
        }
        return ans;
    }   
};

