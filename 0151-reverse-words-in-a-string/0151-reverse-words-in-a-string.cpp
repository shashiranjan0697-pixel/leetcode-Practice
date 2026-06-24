class Solution {
public:
    string reverseWords(string s) {
        // reverse(s.begin(), s.end());
        // int prev = 0;
        // string temp = "";
        // for(int i=0;i<=s.length();i++){
        //     if( i==s.length() || s[i]==' ' ){
        //         reverse(temp.begin(), temp.end());
        //         s.replace(prev, i-prev, temp);
        //         prev = i+1;
        //         temp.clear();
        //     }
        //     else temp+=s[i];
        // }
        stack<string> st;
        string temp = "";
        for(auto c: s){
            if(c==' ') {
                if (!temp.empty()) {
                    st.push(temp);
                    temp.clear();
                }
            }
            else {
                temp+=c;
            }
        }
        if (!temp.empty()) {
            st.push(temp);
        }        
        s.clear();
        while(!st.empty()){
            s+=st.top();
            st.pop();
            s+=" ";
        }
        s.pop_back();
    return s;
    }
};