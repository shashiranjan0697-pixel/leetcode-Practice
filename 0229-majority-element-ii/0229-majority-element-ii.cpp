class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> mp;
        for(auto &ele : nums){
            mp[ele]++;
            if(mp[ele] > n/3){
                ans.push_back(ele);
                mp[ele] = INT_MIN;
            }
        }
    return ans;
    }
};