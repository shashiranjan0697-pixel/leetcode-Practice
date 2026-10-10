class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char,int> mp;
        vector<string> ans;
        string s = "qwertyuiop";
        for(auto ele : s) 
            mp[ele]=1;

        s = "asdfghjkl";
        for(auto ele : s) 
            mp[ele]=2;

        s = "zxcvbnm";
        for(auto ele : s) 
            mp[ele]=3;

        for(auto ele : words) {
            int idx = mp[tolower(ele[0])];
            bool flag = true;
            for(auto c : ele) {
                if(mp[tolower(c)] != idx){
                    flag = false;
                    break;
                }
            }
            if(flag) ans.push_back(ele);
        }
    return ans;
    }
};