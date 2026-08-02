class Solution {
public:
    int dp[500][500];
    int f(vector<int>& piles, int i, int j){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int stone = 0;
        dp[i][j]=max(
            piles[i]+min(f(piles, i+2,j), f(piles, i+1,j-1)),
            piles[j]+ min(f(piles, i, j-2), f(piles, i+1,j-1))
        );
    return dp[i][j];
    }
    
    bool stoneGame(vector<int>& piles) {
    //     int n = piles.size();
    //     memset(dp, -1, sizeof(dp));
    //     int a = f(piles, 0, n-1);
    //     int b = 0;
    //     for(auto ele : piles) b+=ele;
    //     b=b-a;
    // return a>b;
    return true;
    }
};