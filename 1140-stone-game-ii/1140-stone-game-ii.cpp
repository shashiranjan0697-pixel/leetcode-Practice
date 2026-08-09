class Solution {
public:
    vector<vector<int>> dp;
    vector<int> suffix;

    int f(vector<int>& piles, int m, int i) {
        int n = piles.size();

        if (i >= n)
            return 0;

        if (2 * m >= n - i)
            return suffix[i];

        if (dp[i][m] != -1)
            return dp[i][m];

        int ans = 0;

        for (int x = 1; x <= 2 * m; x++) {
            int opponent = f(piles, max(m, x), i + x);

            // All stones from i onward minus what opponent gets
            ans = max(ans, suffix[i] - opponent);
        }

        return dp[i][m] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        suffix.resize(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        dp.assign(n, vector<int>(n + 1, -1));

        return f(piles, 1, 0);
    }
};