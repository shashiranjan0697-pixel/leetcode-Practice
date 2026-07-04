class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int count =1;
        int i=0, j=1;
        int len = 1;
        while(j<nums.size()){
            if(nums[j]>nums[j-1]) {
                count++;
                j++;
            }
            else{
                len = max(len, count);
                count=1;
                i = j;
                j++;
            }
        }
        len = max(len, count);
    return len;
    }
};