class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int>st(nums.begin(), nums.end());

        if(n==0) return 0;

        int ans =0;

        for(auto x : st){

            if(!st.count(x-1)){

                int curr = x;
                int len = 1;

                while(st.count(curr+1)){
                    len++;
                    curr++;
                }

                ans = max(ans, len);
            }
        }
    return ans;     
    }
};