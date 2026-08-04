class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int i=0, j=1;
        while(j<n){
            int temp = nums[i];
            int diff = nums[j]-temp;
            while(diff>1){
                temp++;
                ans.push_back(temp);
                diff = nums[j]-temp;
            }
            i++;
            j++;
        }
    return ans;
    }
};