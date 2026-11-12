class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxInc = 1;
        int maxDec = 1;
        int currInc = 1;
        int currDec = 1;
        for(int i=1; i<n; i++) {

            if(nums[i] > nums[i-1]){
                currInc++;
                maxDec = max(maxDec, currDec);
                currDec = 1;
            }

            if(nums[i] < nums[i-1]){
                currDec++;
                maxInc = max(maxInc, currInc);
                currInc = 1;
            }

            if(nums[i] == nums[i-1]) {
                maxInc = max(maxInc, currInc);
                currInc = 1;
                maxDec = max(maxDec, currDec);
                currDec = 1;
            }
        }
    return max({maxDec, maxInc, currDec, currInc});
    }
};