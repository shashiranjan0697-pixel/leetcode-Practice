class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end(), [](int a, int b) {
            return a>b;
        });

        int myScore = 0;
        int i=1, j=piles.size()-1;
        
        while(i<j){
            myScore += piles[i];
            i+=2;
            j--;
        }
            
        
    return myScore;
    }
};