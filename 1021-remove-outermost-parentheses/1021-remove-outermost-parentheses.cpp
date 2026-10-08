class Solution {
public:
    string removeOuterParentheses(string s) {
        // stack<char> st;
        int st = 0;
        string temp = "";
        string ans = "";
        for(auto ele : s) {
            if(st!=0 && ele == ')'){
                st--;
                temp += ele;
                if(st==0){
                    temp.erase(0,1);
                    temp.erase(temp.size()-1,1);
                    ans += temp;
                    temp = "";
                }
                continue;
            }
            else {
                temp += ele;
                st++;
            }
        }
    return ans;
    }
};