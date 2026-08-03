#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        
        // dp0 = dp[i], dp1 = dp[i+1], dp2 = dp[i+2], dp3 = dp[i+3]
        int dp1 = 0, dp2 = 0, dp3 = 0;
        int dp0 = 0;

        for (int i = n - 1; i >= 0; --i) {
            int current_take = 0;
            dp0 = -1e9; // Initialize with a very small number

            // Option 1: Take 1 stone
            current_take += stoneValue[i];
            dp0 = max(dp0, current_take - dp1);

            // Option 2: Take 2 stones (if available)
            if (i + 1 < n) {
                current_take += stoneValue[i + 1];
                dp0 = max(dp0, current_take - dp2);
            }

            // Option 3: Take 3 stones (if available)
            if (i + 2 < n) {
                current_take += stoneValue[i + 2];
                dp0 = max(dp0, current_take - dp3);
            }

            // Shift states for next iteration (moving backwards)
            dp3 = dp2;
            dp2 = dp1;
            dp1 = dp0;
        }

        // Output result based on Alice's maximum score difference
        if (dp0 > 0) return "Alice";
        if (dp0 < 0) return "Bob";
        return "Tie";
    }
};