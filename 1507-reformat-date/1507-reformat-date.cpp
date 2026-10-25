class Solution {
public:
    
    string reformatDate(string date) {
        int n = date.length();
        unordered_map<string, string> mp;
        mp["Jan"]="01"; mp["Feb"]="02"; mp["Mar"]="03"; mp["Apr"]="04"; 
        mp["May"]="05"; mp["Jun"]="06"; mp["Jul"]="07"; mp["Aug"]="08";
        mp["Sep"]="09"; mp["Oct"]="10"; mp["Nov"]="11"; mp["Dec"]="12";
        string ans = "";
        ans +=date[n-4];
        ans +=date[n-3];
        ans +=date[n-2];
        ans +=date[n-1];
        ans +="-";
        string temp = date.substr(n-8,3);
        cout<<n;
        ans += mp[temp];
        ans += "-";
        if(n == 13){
            ans += date.substr(0,2);
        }
        else {
            ans += "0";
            ans += date[0];
        }
    return ans;
    }
};