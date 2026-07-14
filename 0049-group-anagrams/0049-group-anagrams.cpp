class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;;
        unordered_map<string, vector<string> > mp;
        for(int i=0;i<strs.size();i++){
            string s = strs[i];
            sort(s.begin(),s.end());
            mp[s].push_back(strs[i]);
        }
        for(auto ele : mp){
            vector<string> temp;
            for(auto x : ele.second){
                temp.push_back(x);
            }
            ans.push_back(temp);
            temp.clear();
        }
    return ans;
    }
};