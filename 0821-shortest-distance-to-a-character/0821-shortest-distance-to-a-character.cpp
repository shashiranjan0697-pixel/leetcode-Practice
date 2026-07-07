class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.length();
        vector<int> ans(n,0);
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            if(s[i]==c){
                st.insert(i);
            }
        }

        for(int i = 0 ; i<n;i++){
            if(st.count(i)) continue;
            int dist = INT_MAX;
            for(auto x : st){    
                dist = min(dist, abs(x-i));
            }
            ans[i] = dist;
        }
    return ans;
    }
};