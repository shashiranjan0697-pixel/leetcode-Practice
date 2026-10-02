class Solution {
public:
    void f(vector<string>& ans, string s, int open, int close, int n) {
        if(close == n) {
            ans.push_back(s);
            return;
        }

        if(open < n) { 
            f(ans, s+"(", open+1, close, n);
        }
        if(close < open){
            f(ans, s+")", open, close+1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        f(ans, "", 0, 0, n);
    return ans;
    }
};