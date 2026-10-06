class Solution {
public:
    int minAddToMakeValid(string s) {

        stack<char>st;

        for(auto ele : s){
            if(!st.empty() && st.top() == '(' && ele == ')') {
                st.pop();
                continue;
            }
            else st.push(ele);
        }
    return st.size();
    }
};