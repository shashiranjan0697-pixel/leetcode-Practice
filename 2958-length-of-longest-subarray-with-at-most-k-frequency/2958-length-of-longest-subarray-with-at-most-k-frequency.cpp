class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans = 0;
        int n = nums.size();
        int i=0, j=0, freq=0;
        while(i<=j && j<n){
            if(mp.find(nums[j])==mp.end()){
                mp[nums[j]]++;
                j++;
            }
            else if (mp[nums[j]] < k) {
                mp[nums[j]]++;
                j++;
            }
            else {
                mp[nums[i]]--;
                i++;
            }
        ans = max(ans, j-i);
        }
    return ans;    
    }
};