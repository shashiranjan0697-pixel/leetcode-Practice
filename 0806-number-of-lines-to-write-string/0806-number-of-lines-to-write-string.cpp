class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int count = 1;
        int sum = 0;
        for(auto c : s){
            int temp = c - 'a';
            sum+= widths[temp];
            if(sum > 100){
                sum= widths[temp];
                count++;
            }
        }
    return {count, sum};
    }
};