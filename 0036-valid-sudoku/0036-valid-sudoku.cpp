class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // row check
        for(int i=0; i<9; i++) {
            unordered_set<char> row;
            for(int j=0; j<9; j++) {
                if(board[i][j] != '.') {
                    if(row.count(board[i][j]) ) return false;
                    row.insert(board[i][j]);
                }
            }
        }

        // col check
        for(int i=0; i<9; i++) {
            unordered_set<char> col;
            for(int j=0; j<9; j++) {
                if(board[j][i] != '.') {
                    if(col.count(board[j][i]) ) return false;
                    col.insert(board[j][i]);
                }
            }
        }

        // 3 × 3 Box check
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {

                unordered_set<char> box;

                for (int r = i; r < i + 3; r++) {
                    for (int c = j; c < j + 3; c++) {

                        if (board[r][c] != '.') {
                            if (box.count(board[r][c]))
                                return false;

                            box.insert(board[r][c]);
                        }
                    }
                }
            }
        }
    return true;
    }
};