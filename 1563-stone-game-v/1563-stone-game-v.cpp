class Solution {
public:
    vector<vector<int>> dp;
    vector<int> preSum;
    vector<int> postSum;

    int f(vector<int>& stone, int l, int r){
        if(l==r) return 0;

        if(dp[l][r] != -1) return dp[l][r];

        int ans = 0;

        for(int i=l; i<r; i++){
            int leftSum = preSum[i] - (l>0 ? preSum[l-1] : 0);
            int rightSum  = preSum[r] - preSum[i];

            if(leftSum < rightSum){
                ans = max(ans, leftSum + f(stone, l, i));
            }
            else if(leftSum > rightSum){
                ans = max(ans, rightSum + f(stone, i+1, r));
            }
            else ans = max({
                ans,
                leftSum + f(stone, l, i),
                rightSum + f(stone, i+1, r)
            });
        }
    return dp[l][r] = ans;
    }

    int stoneGameV(vector<int>& stone) {
        int n = stone.size();

        dp.resize(n, vector<int>(n,-1));
        preSum.resize(n);
        postSum.resize(n);

        preSum[0] = stone[0];
        for(int i = 1; i < n; i++)
            preSum[i] = preSum[i-1] + stone[i];

        postSum[n-1] = stone[n-1];
        for(int i = n-2; i >= 0; i--)
            postSum[i] = postSum[i+1] + stone[i];

    return f(stone, 0, n-1);
    }
};