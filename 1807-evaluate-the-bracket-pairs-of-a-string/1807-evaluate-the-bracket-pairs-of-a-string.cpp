class Solution {
public:
    // unordered_map<string, string> mp;

    // void findKeyVal(string key, vector<vector<string>>& knowledge) {
    //     for(auto &ele : knowledge) {
    //         if(ele[0] == key) {
    //             mp[key] = ele[1];
    //             return;
    //         }
    //     }
    //     mp[key] = "?";
    // }

    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans = "";
        unordered_map<string, string> mp;

        for(auto &ele : knowledge) {
            mp[ele[0]] = ele[1];
        }

        for(int i = 0; i < s.length(); i++) {

            if(s[i] == '(') {
                int start = i + 1;

                while(s[i] != ')') {
                    i++;
                }

                string key = s.substr(start, i - start);

                if(mp.find(key) != mp.end())
                    ans += mp[key];
                else
                    ans += "?";
            }
            else {
                ans += s[i];
            }
        }

    return ans;
    }
};