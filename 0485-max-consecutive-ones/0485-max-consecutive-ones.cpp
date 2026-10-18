class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0;
        int curr = 0;
        for(auto ele : nums) {
            if(ele == 1) {
                curr++;
                maxi = max(maxi, curr);
            }
            else{
                curr = 0;
            }
        }
    return maxi;
    }
};