class Solution {
public:
    bool checkString(string s) {
        int a=-1, b=100;
        for(int i=0; i<s.length(); i++){
            if(s[i] == 'a') 
                a = i;
            else
                b = min(b, i);
        }
    return a<b;
    }
};