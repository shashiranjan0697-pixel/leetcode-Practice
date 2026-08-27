class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int> ans;
        unordered_set<int> st(nums1.begin(), nums1.end());
        unordered_set<int> st2(nums2.begin(), nums2.end());
        unordered_set<int> st3(nums3.begin(), nums3.end());

        for(auto ele : st2){
            if(st.count(ele)){
                ans.push_back(ele);
            }
            st.insert(ele);
        }

        for(auto ele : st3){
            if(st.count(ele)){
                ans.push_back(ele);
            }
            st.insert(ele);
        }
    unordered_set<int> res(ans.begin(), ans.end());
    ans.clear();
    for(auto x : res) ans.push_back(x);
    return ans;
    }
};