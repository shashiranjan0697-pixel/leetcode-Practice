class Solution {
public:
    bool detectCapitalUse(string s) {
        int  n = s.length();
        int count = 0;

        for(int i=0; i<n; i++) {
            if(s[i] <= 'Z') 
                count++;
        }

        if(count == 0 || (count == 1 && s[0] <= 'Z') || count == n)
            return true;

    return false;
    }
};