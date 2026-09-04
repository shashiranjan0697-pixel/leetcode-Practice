class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> lg, sm;
        
        lg.resize(n, -1);
        sm.resize(n, INT_MAX);
        lg[0] = nums[0];
        sm[n-1] = nums[n-1];

        for(int i=1; i<n; i++){
            lg[i] = max(lg[i-1], nums[i]);
        }

        for(int i=n-2; i>=0; i--){
            sm[i] = min(sm[i+1], nums[i]);
        }

        for(int i=0; i<n; i++){
            // cout<<"("<<lg[i] <<", "<< sm[i]<<") ";
           if(lg[i] - sm[i] <= k) return i;
        }
    return -1;
    }
};