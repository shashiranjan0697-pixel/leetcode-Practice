class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = 0;
        for(auto &ele : nums)
            maxi = max(maxi, ele);

        int count = 0;
        for(auto &ele : nums)
            count += maxi-ele;
    
    return count;
    }
};