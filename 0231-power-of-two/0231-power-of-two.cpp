class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long start = 1;
        while(start<=n){

            if(start == n) return true;
            else start*=2;
        }
    return false;
    }
};