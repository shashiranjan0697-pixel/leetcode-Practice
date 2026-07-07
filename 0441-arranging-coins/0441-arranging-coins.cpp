class Solution {
public:
    int arrangeCoins(int n) {
        int i =1;
        int count =0;
        while(true){
            if(n<i) break;
            count++;
            n-=i;
            i++;
        }
    return count;
    }
};