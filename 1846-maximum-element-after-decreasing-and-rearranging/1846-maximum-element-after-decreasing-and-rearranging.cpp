class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int ans = 0;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int len = 0 ;
        arr[0]=1;
        for(int i=1;i<n;i++){
            arr[i] = min(arr[i], arr[i-1]+1);
        }
        
    return arr[n-1];
    }
};