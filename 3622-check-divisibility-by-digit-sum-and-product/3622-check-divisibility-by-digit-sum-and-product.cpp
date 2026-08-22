class Solution {
public:
    int f (int n){
        int sum = 0, prod = 1;
        while(n>0){
            sum += n%10;
            prod *= n%10;
            n/=10;
        }
    return (sum+prod);
    }
    bool checkDivisibility(int n) {
        
    return n % f(n) == 0;
    }
};