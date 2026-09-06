class Solution {
public:
    int dp[1001][1001];
    int f(string s, string t, int i, int j) {
        int n = s.length();
        int m = t.length();

        if(j>=m) return 1;
        if(i>=n) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if (s[i] == t[j]) {
            return dp[i][j] =
                f(s, t, i + 1, j + 1) +
                f(s, t, i + 1, j);
        }

    return dp[i][j] = f(s, t, i + 1, j);
    }

    int numDistinct(string s, string t) {
        memset(dp, -1, sizeof(dp));
    return f(s, t , 0, 0);
    }
};