class Solution {
public:
    int dp[25][25];
    int f(vector<int>& nums, int i, int j){
        int cost = 0;
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        dp[i][j]=max((nums[i]+ min(f(nums, i+2, j), f(nums, i+1, j-1))),
            nums[j]+min(f(nums,i,j-2), f(nums,i+1,j-1))
            );
    return dp[i][j];
    }
    bool predictTheWinner(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int n = nums.size();
        int totalScore = 0;
        for(auto ele : nums) totalScore += ele;
        int a = f(nums, 0, n-1);
        int b = totalScore-a;

    return a>=b;
    }
};