class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> missing;
        int start = 1;
        for(int i=0; i<n; i++){
            while(start != arr[i]){
                missing.push_back(start);
                start++;
            }
        start++;
        }
        while(missing.size() < k) {
            missing.push_back(start);
                start++;
        }
        
    return missing[k-1];
    }
};