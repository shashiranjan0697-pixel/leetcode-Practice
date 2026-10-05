class Solution {
public:
    int scoreOfParentheses(string s) {
        stack <int> st;
        st.push(0);
        for(auto ele : s) {
            
            if(ele == '(') st.push(0);

            else{
                int curr = st.top();
                st.pop();

                if(curr == 0){
                    curr = 1;
                }
                else{
                    curr *= 2;
                }
            st.top() += curr;
            }
        }
    return st.top();
    }
};