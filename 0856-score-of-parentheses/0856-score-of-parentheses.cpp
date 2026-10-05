class Solution {
public:
    int scoreOfParentheses(string s) {
        stack <int> st;
        st.push(0);
        for(auto ele : s) {
            
            if(ele == '(') st.push(0);

            else{
                int ele = st.top();
                st.pop();

                if(ele == 0){
                    ele = 1;
                }
                else{
                    ele *= 2;
                }
            st.top() += ele;
            }
        }
    return st.top();
    }
};