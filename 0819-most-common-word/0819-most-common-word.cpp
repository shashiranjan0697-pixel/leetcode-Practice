class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> mp;
        unordered_set<string> ban(banned.begin(),banned.end());
        int n=paragraph.size();
        string check="";
        for(auto ch : paragraph){
            ch = tolower(ch);
            if(isalpha(ch)){
                check+=ch;
            }
            
            else{
                if(!check.empty()){
                    mp[check]++;
                    check.clear();
                }
            }
        }
        if(!check.empty())  mp[check]++;
        string ans;
        int quant = 0;
        for(auto x : mp){
            if(x.second > quant && !ban.count(x.first)){
                ans = x.first;
                quant = x.second;
            }
        }
    return ans;
    }
};