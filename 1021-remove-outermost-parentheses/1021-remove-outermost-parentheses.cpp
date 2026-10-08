class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string temp = "";
        string ans = "";
        for(auto ele : s) {
            if(!st.empty() && st.top() =='(' && ele == ')'){
                st.pop();
                temp += ele;
                if(st.empty()){
                    temp.erase(0,1);
                    temp.erase(temp.size()-1,1);
                    ans += temp;
                    temp = "";
                }
                continue;
            }
            else {
                temp += ele;
                st.push(ele);
            }
        }
    return ans;
    }
};