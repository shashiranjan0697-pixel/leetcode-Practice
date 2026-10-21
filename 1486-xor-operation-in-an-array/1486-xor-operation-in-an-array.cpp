class Solution {
public:
    int xorOperation(int n, int start) {
        int ans = start;
        while(n-1>0){
            start += 2;
            ans ^= start;
            n--;
        }
    return ans;
    }
};