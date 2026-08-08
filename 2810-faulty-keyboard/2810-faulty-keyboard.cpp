class Solution {
public:
    string finalString(string s) {
        for(int i=0;i<s.length();i++){
            while(s[i]=='i'){
                reverse(s.begin(),s.begin()+i);
                s.replace(i,1,"");    
            }
        }
    return s;
    }
};