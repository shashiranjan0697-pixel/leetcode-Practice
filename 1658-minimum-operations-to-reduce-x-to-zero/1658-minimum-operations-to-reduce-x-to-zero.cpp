class Solution {
public:

    // vector<vector<vector<int>>> dp;

    // int f(vector<int>& nums, int x, int i, int j) {

    //     if(x == 0) return 0;

    //     if (i > j || x < 0)
    //         return INT_MAX;

    //     if(dp[x][i][j] != -1) 
    //         return dp[x][i][j];

    //     int left = f(nums, x-nums[i], i+1, j);
    //     int right = f(nums, x-nums[j], i, j-1);
        
    //     if (left != INT_MAX)
    //         left++;

    //     if (right != INT_MAX)
    //         right++;

    // return dp[x][i][j] = min(left, right);
    // }

    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        long long total = 0;
        for(int i=0; i<n; i++) {
            total += nums[i];
        }

        long long target = total - x;

        if(target == 0) return n;

        if(target < 0) return -1;

        unordered_map<long long, int> mp;
        mp[0] = -1;
        long long prefix = 0;
        int longest = -1;
        for(int i=0; i<n; i++) {
            prefix += nums[i];

            if(mp.find(prefix - target)!=mp.end()){
                int j = mp[prefix - target];

                longest = max(longest, i-j);
            }

            if(mp.find(prefix)==mp.end()) {
                mp[prefix] = i;
            }
        }

    return longest == -1 ? -1 : n-longest;
    }
};