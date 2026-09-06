class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.size();
        int m = s1.size();
        unordered_map<char, int> freq, mp;
        for(auto ele : s1){
            freq[ele]++;
        }
        
        int i=0,j=0;
        while(j<n) {
            
            mp[s2[j]]++;

            if(j-i+1 > m ) {
                mp[s2[i]]--;
                if (mp[s2[i]] == 0) {
                    mp.erase(s2[i]);
                }
                i++;
            }
                    
            if(j-i+1 == m && freq == mp) return true;

        j++;
        }
    return false;    
    }
};