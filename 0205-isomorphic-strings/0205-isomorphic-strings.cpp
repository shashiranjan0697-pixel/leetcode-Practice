class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        unordered_map<char, char> mp, mp1;
        for(int i = 0; i<n; i++){

            if(mp.count(s[i])){
                if(mp[s[i]]!=t[i]) return false;
            }
            else mp[s[i]]=t[i];

            if(mp1.count(t[i])){
                if(mp1[t[i]]!=s[i]) return false;
            }
            else mp1[t[i]]=s[i];
        }
    return true;
    }
};