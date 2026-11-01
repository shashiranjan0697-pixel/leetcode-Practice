class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int total = 0, curr = 0;
        for(int i=0; i<n; i++){
            curr = 0;
            for(int j=i; j<n; j++){
                curr += arr[j];
                if((i-j+1)%2 != 0)
                    total += curr;
            }
        }
    return total;
    }
};