class Solution {
public:
    // // vector<long long> ans;
    // void f(vector<int>& nums, int k, int i){
    
    //     if(i >= nums.size()) return;

    //     long long prod = 1;

    //     for(int j = i; j < nums.size(); j++) {

    //         prod = (prod * nums[j]) % k;

    //         ans[prod]++;

    //     }
    // f(nums, k, i+1);
    // }
    vector<long long> resultArray(vector<int>& nums, int k) {

    vector<long long> ans(k, 0);

    vector<long long> dp(k, 0);

        for(int x : nums) {

            vector<long long> newDp(k, 0);

            int rem = x % k;

            for(int r = 0; r < k; r++) {
                int newRem = (r * rem) % k;

                newDp[newRem] += dp[r];
            }

            newDp[rem]++;

            for(int r = 0; r < k; r++) {
                ans[r] += newDp[r];
            }

            dp = newDp;
        }

    return ans;
    }
};