class Solution {
public:
    int scoreOfString(string s) {
        int score = 0;
        for(int i=1; i<s.length(); i++){
            int p = s[i-1];
            int t = s[i];
            score+=abs(t-p);
        }
    return score;
    }
};