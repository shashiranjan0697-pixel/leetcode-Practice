class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> same;
        map<pair<int, int>, int> mp;

        int base = 0;

        for(int i = 0; i < n - 1; i++) {
            int a = nums[i];
            int b = nums[i + 1];

            if(a == b) {
                base++;
            } else {
                int x = min(a, b);
                int y = max(a, b);

                mp[{x, y}]++;
            }
        }

        int ans = base;

        for(auto &[p, cnt] : mp) {
            ans = max(ans, base + cnt);
        }

        return ans;
    }
};