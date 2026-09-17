class Solution {
public:

    int minSumOfLengths(vector<int>& arr, int target) {
        
        int n = arr.size();

        vector<int> best(n + 1, INT_MAX);
        int i=0, j=0, ans = INT_MAX, bestMin = INT_MAX;
        long long sum = 0;
        while(j<n) {
            sum += arr[j];

            while(sum > target) {
                sum -= arr[i];
                i++;
            }

            if(sum == target) {
                int len = j-i+1;
                if(i>0 && best[i-1] != INT_MAX) {
                    ans = min(ans, best[i-1] + len);
                }
                bestMin = min(bestMin, len);
            }
        best[j] =  bestMin;
        j++;
        }
        
    return ans == INT_MAX ? -1 : ans;
    }
};