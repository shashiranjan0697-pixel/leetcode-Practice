class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xorr = 0, len = 0;
       bool hasNonZero = false;
       for(int i=0; i<n; i++) {
            xorr ^= nums[i];
            if(nums[i] != 0) hasNonZero = true;
        }
        if(xorr) return n;

    return hasNonZero ? n-1 : 0;
    }
};