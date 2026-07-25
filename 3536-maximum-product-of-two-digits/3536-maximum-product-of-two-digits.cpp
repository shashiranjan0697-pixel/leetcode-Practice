class Solution {
public:
    void vecOfDig(int n, vector<int>& dig){
        while(n>0){
            int temp = n%10;
            dig.push_back(temp);
            n/=10;
        }
    }
    int maxProduct(int n) {
        vector<int> dig;
        vecOfDig(n, dig);
        int m = dig.size();
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(i==j) continue;
                ans=max(ans, (dig[i]*dig[j]));
            }
        }
    return ans;
    }
};