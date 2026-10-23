class Solution {
public:

    int cus_Stoi(string s){
        int ans = 0;
        for(auto ele : s){
            ans *= 10;
            ans += ele - 'a';
        }
    return ans;
    }

    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int val = cus_Stoi(firstWord) + cus_Stoi(secondWord);
        int target = cus_Stoi(targetWord);
    return val == target;
    }
};