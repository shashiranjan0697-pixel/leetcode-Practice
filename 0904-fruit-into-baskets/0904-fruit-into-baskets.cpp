class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int i=0, j=0, ans = 0;

        while(i<=j && j<fruits.size()){
            
            if(mp.size() <= 2) ans = max(ans, j-i);
            else{
                mp[fruits[i]]--;
                if(mp[fruits[i]] == 0) mp.erase(fruits[i]);
                i++;
            }
        mp[fruits[j]]++;
        j++;
        }
        if(mp.size() <= 2) ans = max(ans, j-i);
    return ans;
    }
};