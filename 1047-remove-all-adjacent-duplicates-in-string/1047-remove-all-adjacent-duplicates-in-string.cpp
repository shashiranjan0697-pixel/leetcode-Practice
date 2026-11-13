class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        for(auto ele : s ){
            if(st.empty() || st.top()!=ele){
                st.push(ele);
            }
            else st.pop();
        }
        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
    return ans;
    }
};