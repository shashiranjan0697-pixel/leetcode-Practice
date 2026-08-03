class Solution {
public:
    string stoneGameIII(vector<int>& stone) {
        int n = stone.size();
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            int take1 = stone[i] - dp[i + 1];

            int take2 = INT_MIN;
            if (i + 1 < n)
                take2 = stone[i] + stone[i + 1] - dp[i + 2];

            int take3 = INT_MIN;
            if (i + 2 < n)
                take3 = stone[i] + stone[i + 1] + stone[i + 2] - dp[i + 3];

            dp[i] = max({take1, take2, take3});
        }

        if (dp[0] == 0)
            return "Tie";
        return dp[0] > 0 ? "Alice" : "Bob";
    }
};