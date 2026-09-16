class Solution {
public:
    int m = 1e9 + 7;
    int dp[1001][1001];
    int f (int i, int n , int k) {

        if(k == 0) 
            return 1;

        if(i >= n) 
            return 0;

        if(dp[i][k] != -1)
            return dp[i][k];

        int take = 0;
        for(int j=i+1; j<n; j++) {
            take = (take + f(j,n, k-1)) % m;
        }

        int skip = f(i+1, n, k) % m;

    return dp[i][k] = (skip+take) % m;
    }

    int numberOfSets(int n, int k) {
        // memset(dp, -1, sizeof(dp));

        for(int i=0;i<n;i++)
            dp[0][i] = 1;

        for(int p=1; p<=k; p++) {
            vector<int> sufSum(n+1, 0);
                for(int x=n-1; x>=0; x--) {
                    sufSum[x] = (sufSum[x+1] + dp[p-1][x]) % m;
                }
            for(int i=n-1; i>=0; i--){

                int take = sufSum[i+1];
                
                int skip = dp[p][i+1] % m; 

            dp[p][i] = (skip+take) % m;
            }
        }

    return dp[k][0];
    // return f(0, n, k) % m; 
    }
};