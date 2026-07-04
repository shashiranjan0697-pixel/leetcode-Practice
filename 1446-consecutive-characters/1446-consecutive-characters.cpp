class Solution {
public:
    int maxPower(string s) {
        int count = 1;
        int len = 1;
        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1]) {
                count++;
            }
            
            else{
                len = max(len, count);
                count = 1;
            }
        }
        len = max(len, count);
    return len;
    }
};