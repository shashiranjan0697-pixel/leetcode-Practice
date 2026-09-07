class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;

        vector<long long> end(26, 0);

        long long total = 0;

        for(char c : s) {
            int idx = c - 'a';

            long long old = end[idx];

            // New subsequences ending with c
            end[idx] = (total + 1) % MOD;

            // Update total
            total = (total + end[idx] - old + MOD) % MOD;
        }

        return total;
    }
};