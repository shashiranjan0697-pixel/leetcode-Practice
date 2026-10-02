class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        vector<int> last(26);

        for(int i=0; i<n; i++){
            last[s[i]-'a'] = i;
        }

        vector<bool> visited(26, false);
        stack<char> st;

        for(int i=0; i<n; i++) {
            int ele = s[i];

            if(visited[ele-'a']) {
                continue;
            }

            while(!st.empty() && 
                    st.top() > ele &&
                    last[st.top() - 'a'] > i
                ) {
                    visited[st.top() - 'a'] = false;
                    st.pop();
                }
            st.push(ele);
            visited[ele - 'a'] = true;
        }
        string ans = "";

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        
    return ans;
    }
};