class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=0;
        for(auto ele : nums) {
            cout<<ele<<" ,";
            if(ele>=k) break;
            else ans++;
        }
    return ans;
    }
};