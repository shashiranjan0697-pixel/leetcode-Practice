class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int ans = INT_MAX;
        for(int i=l; i<=r; i++) {
            int j=0, k=0;
            int curr = 0;
            while(k<n) {
                curr += nums[k];
                
                while(k-j+1 == i){
                    if(curr > 0)
                        ans = min(ans, curr);
                    else
                        ans = max(ans, curr);
                    curr = curr - nums[j];
                    j++;
                }

            k++;
            }
        }
    return ans == INT_MAX ? -1 : ans;
    }
};