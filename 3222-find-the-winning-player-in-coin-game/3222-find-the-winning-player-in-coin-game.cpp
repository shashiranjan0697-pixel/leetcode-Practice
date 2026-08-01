class Solution {
public:
    string winningPlayer(int x, int y) {
        int move = min(x, y/4);
    return move%2==0 ? "Bob" : "Alice"; 
    }
};