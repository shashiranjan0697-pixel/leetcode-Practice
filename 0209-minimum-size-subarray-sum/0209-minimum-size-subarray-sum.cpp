class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int j=0;
        int len = INT_MAX;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            while(sum>=target){
                len = min(len,i-j+1 );
                sum-=nums[j];
                j++;
            }
        } 
    return len>n ? 0 : len;
    }
};