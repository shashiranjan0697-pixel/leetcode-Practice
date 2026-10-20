class Solution {
public:

    int digiSum (int n) {
        int sum = 0;
        while(n>0){
            sum += n%10;
            n/=10;
        }
    return sum;
    }

    int digiProduct (int n) {
        int product = 1;
        while(n>0){
            product *= n%10;
            n/=10;
        }
    return product;
    }

    int subtractProductAndSum(int n) {
        
    return digiProduct(n) - digiSum(n);
    }
};