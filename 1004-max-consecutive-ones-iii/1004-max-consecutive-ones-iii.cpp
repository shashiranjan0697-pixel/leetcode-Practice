class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        int allowed = k;
        int len = 0;
        int i=0,j=0;
        while(j<nums.size()){
            if(nums[j]==1 ){ 
                j++;
            }
            else {
                if(allowed){
                    allowed--;
                    j++;
                }
                else{
                    len = j-i;
                    ans = max(ans, len);
                    while(nums[i]==1) i++;
                    i++;
                    j++;
                }
            }

        }
        len = j-i;
        ans = max(ans, len);
    return ans;
    }
};