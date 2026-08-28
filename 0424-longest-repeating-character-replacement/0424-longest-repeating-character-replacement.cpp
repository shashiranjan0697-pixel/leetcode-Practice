class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;

        int i=0, j=0, len = 0, maxFreq=0;
        while(i<=j && j<s.length()){
           
            if((j-i)-maxFreq <= k) {
                len = max(len, j-i);
            }
            else{
                mp[s[i]]--;
                i++;
            }
            mp[s[j]]++;
            maxFreq = max(maxFreq, mp[s[j]]);
            j++;
        }
        if((j-i)-maxFreq <= k)  len = max(len, j-i);
    return len;
    }
};