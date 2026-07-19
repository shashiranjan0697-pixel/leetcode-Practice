class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char, int> mp;
        unordered_set<char> check;
        for(int i=0;i<s.length();i++){
            mp[s[i]]=i;
        }

        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(check.count(s[i]))
                    continue;
            
            while(!st.empty() && st.top()>s[i] && mp[st.top()]>i){
                check.erase(st.top());
                st.pop();
            }
            
            st.push(s[i]);
            check.insert(s[i]);
        }
        s.clear();
        while(!st.empty()) {
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
    return s;
    }
};