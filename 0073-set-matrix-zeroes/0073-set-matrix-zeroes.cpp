class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        unordered_set <int> row, col;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0) {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }

        for(auto ele : row) {
            for(int i=0; i<m; i++){
                matrix[ele][i]=0;
            }
        }

        for(auto ele : col) {
            for(int i=0; i<n; i++){
                matrix[i][ele]=0;
            }
        }

    }
};