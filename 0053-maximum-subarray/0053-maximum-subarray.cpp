class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, ans = INT_MIN;
        int j=0;

        // if(nums[0] == -1) 
        //     return -1;

        while(j<n){
            sum += nums[j];
            ans = max(ans, sum);
            if(sum < 0) 
                sum = 0;
            j++;
        }
    return ans;
    }
};