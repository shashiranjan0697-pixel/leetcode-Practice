class Solution {
public:
    bool canAliceWin(int n) {
        int cap = 10;
        string player = "Bob";
        while(true){
            player = player == "Bob" ? "Alice" : "Bob";
            if(n<cap) break;
            n-=cap;
            cap--;
        }
    return player == "Alice" ? false : true;
    }
};