class Solution {
public:
    vector<int> maxDepthAfterSplit(string s) {
        vector<int> ans(s.size());
        int depth = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                depth++;
                ans[i] = depth % 2;
            } 
            else {
                ans[i] = depth % 2;
                depth--;
            }
        }

        return ans;
    }
};