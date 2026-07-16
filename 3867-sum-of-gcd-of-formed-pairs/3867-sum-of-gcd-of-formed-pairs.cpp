class Solution {
public:
    int gcd(int os, int es){
        while(true){
            if(os%es == 0) return es;
            int temp = es;
            es = os%es;
            os = temp;
        }
    }
    long long gcdSum(vector<int>& nums) {
        int n =nums.size();
        vector<int>preMx(n);
        vector<int> gcdVec(n);
        preMx[0] = nums[0];
        for(int i=1;i<n;i++){
            preMx[i] =  max(preMx[i-1],nums[i]);
        }
        for(int i=0;i<n;i++){
            gcdVec[i] = gcd(nums[i], preMx[i]);
        }

        sort(gcdVec.begin(), gcdVec.end());
        int i=0,j=n-1;
        long long ans = 0;
        while(i<j){
            ans+=gcd(gcdVec[i], gcdVec[j]);
            i++;
            j--;
        }
    return ans;
    }
};