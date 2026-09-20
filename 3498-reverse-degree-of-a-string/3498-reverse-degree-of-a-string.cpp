class Solution {
public:
    int reverseDegree(string s) {

        int ans = 0;

        for(int i=0; i<s.length(); i++) {

            int temp = s[i] - 'a';

            int val = (26 - temp)*(i+1);

            ans += (val);
        }
    return ans;
    }
};