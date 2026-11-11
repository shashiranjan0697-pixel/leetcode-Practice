class Solution {
public:
    bool check(int n){
        int org = n;
        while(n>0){
            int curr = n%10;
            if(curr == 0 || org%curr != 0)
                return false;
            n /= 10;
        }
    return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i=left; i<=right; i++){
            if(check(i))
                ans.push_back(i);
        }
    return ans;
    }
};