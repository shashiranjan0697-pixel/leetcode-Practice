class Solution {
public:
    vector<vector<vector<int>>> dp;
    bool f(vector<vector<char>>& grid, int i, int j, int val) {
        int n = grid.size();
        int m = grid[0].size();

        if (val < 0) return false;

        if (i == n - 1 && j == m - 1)
            return val == 0;

        if(dp[i][j][val] != -1) return dp[i][j][val];

        bool ans = false;

        // Move Right
        if (j + 1 < m) {
            int newVal = val + (grid[i][j + 1] == '(' ? 1 : -1);

            ans |= f(grid, i, j + 1, newVal);
        }

        // Move Down
        if (i + 1 < n) {
            int newVal = val + (grid[i + 1][j] == '(' ? 1 : -1);

            ans |= f(grid, i + 1, j, newVal);
        }

        return dp[i][j][val] = ans;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        if (grid[0][0] == ')') return false;

        dp.resize(n, vector<vector<int>>(m, vector<int>(m+n+1, -1)));

        return f(grid, 0, 0, 1);
    }
};