class Solution {
private:
    vector<int> set_intersection(unordered_set<int>& s1, unordered_set<int>& s2){
        vector<int> ans;
        for(auto num1 : s1){
            if(s2.count(num1))
                ans.push_back(num1);
        }
        return ans;
    }
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_set<int> s1(nums1.begin(),nums1.end());
        unordered_set<int> s2(nums2.begin(),nums2.end());
        if (s1.size() < s2.size()) return set_intersection(s1,s2);
        else return set_intersection(s2,s1);
    }
};
