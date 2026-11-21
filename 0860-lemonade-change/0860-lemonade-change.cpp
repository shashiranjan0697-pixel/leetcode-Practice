class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int , int> mp;

        for(auto ele : bills) {
            if(ele == 5){
                mp[5]++;
            }
            else if(ele == 10){
                if(mp[5] < 1)
                    return false;
                else {
                    mp[10]++;
                    mp[5]--;
                }
            }
            else {
                if(mp[10]>=1 && mp[5]>=1) {
                    mp[20]++;
                    mp[10]--;
                    mp[5]--;
                }
                else if(mp[5]>=3){
                    mp[20]++;
                    mp[5] = mp[5]-3;
                }
                else 
                    return false;
            }
        }
    return true;
    }
};