class Solution {
public:
    bool isVowel(char c){
        if(c=='a' || c=='A' || c=='e' || c=='E' || c=='I' || c=='i' || c=='o' || c=='O' ||
            c=='U' || c=='u'
        ) return true;
    return false;
    }
    string reverseVowels(string s) {
        int i=0, j=s.length()-1;
        while(i<j){
            bool lft = isVowel(s[i]);
            bool rht = isVowel(s[j]);
            if(lft && rht) {
                swap(s[i], s[j]);
                i++;
                j--;
            }
            else if(!lft && !rht){
                i++;
                j--;
            }
            else if(!lft && rht){
                i++;
            }
            else if(lft && !rht){
                j--;
            }
        }
    return s;
    }
};