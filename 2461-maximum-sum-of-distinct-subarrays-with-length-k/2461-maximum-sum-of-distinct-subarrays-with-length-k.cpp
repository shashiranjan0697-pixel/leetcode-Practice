class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_set<int> st;

        long long ans = 0;
        long long sum = 0;

        int i=0;
        
        for(int j=0; j<n; j++){

            while(st.count(nums[j])){
                sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }

            if(!st.count(nums[j])){
                st.insert(nums[j]);
                sum += nums[j];
            }

            while(st.size()>k){
                sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }

            if(st.size() == k) {
                ans = max(ans, sum);
            }   
        }
    return ans;
    }
};