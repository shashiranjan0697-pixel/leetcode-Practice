class Solution {
public:
    int maxDepth(string s) {
        int depth = 0, braces = 0;
        for(auto ele : s){
            if(ele == '(') {
                braces++;
                depth = max(depth, braces);
            }
            if(ele == ')') braces--;
        }
    return depth;
    }
};