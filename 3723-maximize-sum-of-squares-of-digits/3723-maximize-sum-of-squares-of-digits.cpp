class Solution {
public:
    string maxSumOfSquares(int num, int sum) {

        string ans = "";

        int n = num, s = sum;

        while(n > 0 ){

            if(sum > 9){
                ans += '9';
                sum -= 9;
            }  

            else{
                ans += sum + '0';
                sum -= sum;
            }

        n--;

        }
        
        int check = 0;

        for (char ele : ans){
            check += ele - '0';
        }

        if(check == s) return ans;

    return "";
    }
};