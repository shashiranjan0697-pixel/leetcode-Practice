class Solution {
public:
    int sumOfDigit(int n) {
        int sum = 0;
        while(n>0){
            sum += n%10;
            n/=10;
        }
    return sum;
    }

    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        for(int i=0; i<n; i++){
            if(sumOfDigit(nums[i]) == i) {
                ans = min(ans, i);
            }
        }
    return ans == INT_MAX ? -1 : ans;
    }
};