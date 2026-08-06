class Solution {
public:
    int prod(int n){
        int product = 1;
        while(n>0){
            product*=n%10;
            n/=10;
        }
    return product;
    }
    int smallestNumber(int n, int t) {
        for(int i=n;i<=100;i++){
            int var = prod(i);
            if(var%t==0) return i;
        }
    return -1;
    }
};