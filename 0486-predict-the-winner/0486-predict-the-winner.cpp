class Solution {
public:
    int f(vector<int>& nums, int i, int j){
        int cost = 0;
        if(i>j) return 0;
        cost+=max((nums[i]+ min(f(nums, i+2, j), f(nums, i+1, j-1))),
            nums[j]+min(f(nums,i,j-2), f(nums,i+1,j-1))
            );
    return cost;
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int totalScore = 0;
        for(auto ele : nums) totalScore += ele;
        int a = f(nums, 0, n-1);
        int b = totalScore-a;

    return a>=b;
    }
};