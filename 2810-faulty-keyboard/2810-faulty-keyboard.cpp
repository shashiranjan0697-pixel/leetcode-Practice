class Solution {
public:
    string finalString(string s) {
        string ans="";
        for(auto ele : s){
            if(ele=='i') reverse(ans.begin(), ans.end());
            else ans+=ele;
        }
    return ans;
    }
};