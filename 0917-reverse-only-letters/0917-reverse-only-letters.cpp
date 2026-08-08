class Solution {
public:
    bool isChar(char c){
        if((c>='A' && c<='Z') || (c>='a' && c<='z')) return true;
    return false;
    }
    string reverseOnlyLetters(string s) {
        int i=0, j = s.length()-1;
        while(i<j){
            bool lft = isChar(s[i]);
            bool rht = isChar(s[j]);
            if(lft && rht) {
                swap(s[i],s[j]);
                i++;
                j--;
            }
            else if(!lft && !rht) {
                i++;
                j--;
            }
            else if(!lft && rht) {
                i++;
            }
            else if(lft && !rht) {
                j--;
            }
        }
    return s;
    }
};