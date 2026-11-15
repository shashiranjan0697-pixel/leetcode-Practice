
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();

        unordered_map<int, int> mp;

        // Store score -> original index
        for(int i = 0; i < n; i++) {
            mp[score[i]] = i;
        }

        // Sort scores in descending order
        vector<int> temp = score;
        sort(temp.rbegin(), temp.rend());

        vector<string> ans(n);

        // Assign ranks
        for(int i = 0; i < n; i++) {
            int idx = mp[temp[i]];

            if(i == 0)
                ans[idx] = "Gold Medal";
            else if(i == 1)
                ans[idx] = "Silver Medal";
            else if(i == 2)
                ans[idx] = "Bronze Medal";
            else
                ans[idx] = to_string(i + 1);
        }

        return ans;
    }
};
