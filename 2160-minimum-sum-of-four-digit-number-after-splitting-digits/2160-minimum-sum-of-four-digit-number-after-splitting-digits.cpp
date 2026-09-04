class Solution {
public:
    int minimumSum(int n) {
        vector<int> dig;
        while(n>0) {
            dig.push_back(n%10);
            n/=10;
        }
        sort(dig.begin(), dig.end());
        int case1 = dig[0]*10 + dig[3];
        int case2 = dig[1]*10 + dig[2];
    return case1+case2;
    }
};