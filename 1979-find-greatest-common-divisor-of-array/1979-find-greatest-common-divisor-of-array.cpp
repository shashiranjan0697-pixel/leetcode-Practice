class Solution {
public:
    int gcd(int a, int b){
        while(b){
            int t = b;
            b = a % b;
            a = t;
        }
    return a;
    }
    int findGCD(vector<int>& nums) {
        int mn = INT_MAX, mx=0;
        for (auto ele : nums){
            mn = min(mn, ele);
            mx = max(mx, ele);
        }
    return gcd(mn, mx);
    }
};