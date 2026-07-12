class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
        if(n==1) return 0;
        unordered_map<char, pair<int,int> > mp;
        for(int i=0;i<n;i++){
            mp[s[i]].first++;
            mp[s[i]].second = i;
        } 
        int idx = n;
        for(auto x : mp){
            if(x.second.first == 1){
                idx = min(idx, x.second.second);
            } 
        }
    return idx==n ? -1 : idx;
    }
};