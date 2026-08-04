class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        vector<int> ans;
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());
        cout<<mini<<" "<<maxi;
        for(int i=mini;i<=maxi;i++){
            if(!st.count(i)) ans.push_back(i);
        }
    return ans;
    }
};