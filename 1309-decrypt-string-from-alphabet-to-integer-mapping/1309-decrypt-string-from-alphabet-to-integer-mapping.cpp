class Solution {
public:
    string freqAlphabets(string s) {
        
        string ans = "";
        int i=0, n = s.size();

        while(i<n){
            if(i<n-2 && s[i+2] == '#'){
                int c = 'a' - 1 + stoi(s.substr(i,2));
                char a = c;
                ans += a;
                i += 3;
            }
            else{
                int c = 'a' - 1 + stoi(s.substr(i,1));
                char a = c;
                ans += a;
                i += 1;
            }
        }
    return ans;
    }
};