class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        int ans = 0;
        for(auto x : s) mp[x]++;

        for(auto x : mp){
            if(x.second % 2 == 0) ans+=x.second;
            else if(x.second > 1){
                int temp = x.second % 2;
                ans+=x.second-temp;
            }
        }
    return ans==s.length() ? ans : ++ans;
    }
};