class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();

        vector<int> idx;

        int i=0, count = 0;
        while(i<n){
            if(s[i] == '(') {
                idx.push_back(i);
                i++;
            }

            while(i<n && s[i] != ')' && s[i] != '(') i++;

            if(s[i] == ')') {
                int m = idx.size();
                int start = idx[m-1];
                string rep = s.substr(start+1, i-start-1);
                cout<<rep<<"\n";
                reverse(rep.begin(), rep.end());
                s.replace(start, i-start+1, rep);
                n -= 2;
                i -= 1;
                idx.pop_back();
            }
        }
    return s;
    }
};