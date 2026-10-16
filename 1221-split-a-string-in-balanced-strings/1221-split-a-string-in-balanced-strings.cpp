class Solution {
public:
    int balancedStringSplit(string s) {
        int l = 0, r = 0;
        int count = 0;
        for(auto ele : s) {
            if(ele == 'L') l++;
            if(ele == 'R') r++;

            if(l == r) {
                count++;
                l=0;
                r=0;
            }
        }
    return count;
    }
};