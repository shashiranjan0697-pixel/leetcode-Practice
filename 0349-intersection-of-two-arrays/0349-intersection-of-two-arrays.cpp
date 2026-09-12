class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st(nums2.begin(), nums2.end());
        nums2.clear();
        for (auto &ele : nums1) {
            if(st.count(ele)) {
                st.erase(ele);
                nums2.push_back(ele);
            }
        } 
    return nums2;
    }
};