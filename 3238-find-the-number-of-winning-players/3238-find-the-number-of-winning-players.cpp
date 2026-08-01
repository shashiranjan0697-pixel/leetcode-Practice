class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        unordered_map<int, unordered_map<int, int>> freq;

        for (auto &ele : pick) {
            int player = ele[0];
            int color = ele[1];
            freq[player][color]++;
        }
        int count =0;
        for(int i=0;i<n;i++){
            const auto& det = freq[i];
            for(auto x : det){
                if(x.second>i){
                    count++;
                    break;
                }
            }
        }
    return count;
    }
};