class Solution {
public:
    vector<vector<vector<int>>> dp;

    int f(vector<vector<int>>& grid, int i, int j, int temp) {
        int n = grid.size();
        int m = grid[0].size();

        temp ^= grid[i][j];

        // Destination reached
        if(i == n - 1 && j == m - 1) {
            return temp;
        }

        // Already visited this state
        if(dp[i][j][temp] != -1) {
            return dp[i][j][temp];
        }

        int ans = INT_MAX;

        if(i < n - 1) {
            ans = min(ans, f(grid, i + 1, j, temp));
        }

        if(j < m - 1) {
            ans = min(ans, f(grid, i, j + 1, temp));
        }

        return dp[i][j][temp] = ans;
    }

    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int X = 1024; // Assumes every grid value is less than 1024

        dp.assign(n, vector<vector<int>>(
            m, vector<int>(X, -1)
        ));

        return f(grid, 0, 0, 0);
    }
};