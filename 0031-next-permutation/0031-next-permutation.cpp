class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int breakPoint = -1;

        for(int i=n-1; i>0; i--) {
            if(nums[i-1] < nums[i]) {
                breakPoint = i-1;
                break;
            }
        }

        if(breakPoint == -1){ 
                sort(nums.begin(), nums.end());
                return;
            }
        int temp = 1005;
        for(int i=n-1; i>breakPoint; i--) {
            if(nums[i] > nums[breakPoint]) {
                if(temp < n && nums[temp] > nums[i]){
                    temp = i;
                }
                else if (temp >= n) temp = i;
            }
        }

        swap(nums[temp], nums[breakPoint]);
            
        sort(nums.begin()+breakPoint+1, nums.end());

    }
};