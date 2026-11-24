
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        ans = 0;

        for (int i = 0; i < n; i++) {
            long long prod = 1;
            long long currentGcd = 0;
            long long currentLcm = 1;

            for (int j = i; j < n; j++) {
                if (prod > 1e14) break; 

                prod *= nums[j];
                currentGcd = gcd(currentGcd, (long long)nums[j]);
                currentLcm = (currentLcm / gcd(currentLcm, (long long)nums[j])) * nums[j];

                if (prod == currentLcm * currentGcd) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};