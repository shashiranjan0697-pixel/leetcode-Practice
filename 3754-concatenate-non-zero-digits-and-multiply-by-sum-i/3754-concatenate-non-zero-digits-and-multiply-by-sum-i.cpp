class Solution {
public:
    long long  f(int n, long long &sum){
        string ans = "";
        while(n>0){
            if(n%10!=0) {
                sum+=(n%10);
                ans+=(n%10) + '0';
            }
            n/=10;
        }
        reverse(ans.begin(),ans.end());
        long long x  = stoll(ans);
    return x;
    }
    long long sumAndMultiply(int n) {
        if(n==0) return 0;
        long long sum = 0;
        long long x = f(n, sum);
    return (x*sum);
    }
};