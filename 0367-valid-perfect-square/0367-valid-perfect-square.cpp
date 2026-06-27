class Solution {
public:
    bool isPerfectSquare(int num) {
        int a = sqrt(num);
        for(int i=a-1;i<a+2;i++){
            if(pow(i,2)==num) return true;
        }
    return false;
    }
};