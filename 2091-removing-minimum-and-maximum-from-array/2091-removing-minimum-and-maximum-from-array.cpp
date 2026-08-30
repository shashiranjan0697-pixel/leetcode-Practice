class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int mini=0, maxi=0;

        for(int i=0;i<n;i++){

            if(nums[i]<nums[mini]) mini = i;

            if(nums[i]>nums[maxi]) maxi = i;

        } 

        int case1 = max(mini, maxi) + 1;

        int case2 = max(n-mini, n-maxi);

        int left = 0, right = 0;

        if(mini < maxi) {

            left = mini + 1;
            right = n - maxi;

        } else {

            left = maxi + 1;
            right = n - mini;

        }
        
        int case3 = left + right;

    return min({case1, case2, case3});
    }
};