class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        ans.push_back(arr[0]);
        
        for(int i=1;i<n;i++){
            int m = ans.size();
            vector<int>curr = arr[i];
            if(curr[1] <= ans[m-1][1] ){
                continue;
            }
            else if (curr[0]<= ans[m-1][0] && curr[1] >= ans[m-1][1]) {
                ans.pop_back();
                ans.push_back(arr[i]);
            }
            else{
                ans.push_back(arr[i]);
            }
        }
        
    return ans.size();
    }
};