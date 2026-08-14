class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        unordered_map<char, int>mp;
        int i=0, j=0, len=0;
        while(i<=j && j<n){
            if(mp.find(s[j])==mp.end()  ||  mp[s[j]] < 2){
                mp[s[j]]++;
                j++;
            }
            
            else if(mp[s[j]] >= 2) {
                mp[s[i]]--;
                i++;
            }
        len = max (len, j-i);
        }
    return len;
    }
};