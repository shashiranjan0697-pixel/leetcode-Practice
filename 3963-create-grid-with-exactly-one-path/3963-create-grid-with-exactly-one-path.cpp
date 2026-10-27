class Solution {
public:
    vector<string> createGrid(int m, int n) {
        string temp;
        temp.resize(n,'#');
        vector<string> ans(m, temp);

        ans[0] = string(n, '.');
        for(int i=1; i<m; i++){
            ans[i][n-1]='.';
        }

    return ans;
    }
};