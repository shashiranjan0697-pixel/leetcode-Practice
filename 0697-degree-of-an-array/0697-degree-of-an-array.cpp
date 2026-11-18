class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> freq;
        unordered_map<int, int> first;
        unordered_map<int, int> last;

        int degree = 0;

        for(int i = 0; i < nums.size(); i++) {
            int ele = nums[i];

            freq[ele]++;

            if(first.find(ele) == first.end()) {
                first[ele] = i;
            }

            last[ele] = i;

            degree = max(degree, freq[ele]);
        }

        int ans = nums.size();

        for(auto it : freq) {
            if(it.second == degree) {
                int ele = it.first;
                int len = last[ele] - first[ele] + 1;

                ans = min(ans, len);
            }
        }

        return ans;
    }
};