class Solution {
public:
    bool detectCapitalUse(string s) {
        string temp = s;
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        if(temp == s) return true;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        if(temp == s) return true;
        if(temp[0] <= 'Z') {
            s[0] = s[0] - 32; 
            if(temp == s) return true;
        }
    return false;
    }
};