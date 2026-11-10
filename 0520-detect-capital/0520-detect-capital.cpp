class Solution {
public:
    bool detectCapitalUse(string s) {
        string temp = s;

        // checking by transforming in uppercase 
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        if(temp == s) return true;

        // checking by transforming in lowercase 
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        if(temp == s) return true;

        // checking by if forst char is uppercase rest are lowercase
        if(temp[0] <= 'Z') {
            s[0] = s[0] - 32; 
            if(temp == s) return true;
        }
    // base case
    return false;
    }
};