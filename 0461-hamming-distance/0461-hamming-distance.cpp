class Solution {
public:
    string intToBinary(int n){
        string ans = "";
        while(n>0){
            int temp = n%2;
            if(temp == 1) ans += '1';
            else ans += '0';
            n/=2;
        }
    return ans;
    }

    int hammingDistance(int x, int y) {
        string x1 = intToBinary(x);
        string y1 = intToBinary(y);
        int n = x1.length();
        int m = y1.length();

        if(n>m) {
            while(y1.length() < n) y1 += '0';
        }
        if(n<m) {
            while(x1.length() < m) x1 += '0';
        }
        reverse(x1.begin(), x1.end());
        reverse(y1.begin(), y1.end());
        int count = 0;
        for(int i=0; i<x1.length(); i++){
            if(x1[i] != y1[i]) count++;
        }
    return count;
    }
};