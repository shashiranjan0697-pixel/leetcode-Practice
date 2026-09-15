class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {

            // Don't end a palindrome at i-1
            dp[i] = dp[i - 1];

            // Check palindrome of length k
            if (i >= k) {
                bool ok = true;

                int l = i - k;
                int r = i - 1;

                while (l < r) {
                    if (s[l] != s[r]) {
                        ok = false;
                        break;
                    }
                    l++;
                    r--;
                }

                if (ok) {
                    dp[i] = max(dp[i], dp[i - k] + 1);
                }
            }

            // Check palindrome of length k+1
            if (i >= k + 1) {
                bool ok = true;

                int l = i - (k + 1);
                int r = i - 1;

                while (l < r) {
                    if (s[l] != s[r]) {
                        ok = false;
                        break;
                    }
                    l++;
                    r--;
                }

                if (ok) {
                    dp[i] = max(dp[i], dp[i - (k + 1)] + 1);
                }
            }
        }

        return dp[n];
    }
};