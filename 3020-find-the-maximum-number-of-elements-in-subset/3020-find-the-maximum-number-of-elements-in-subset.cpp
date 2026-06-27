
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> mp;

        for(auto x : nums) mp[x]++;
        int ans = 1;
        
        for(auto &[key , count] : mp){
            if(key==1){
                if(count%2==0) ans = max(ans, count-1);
                else ans = max(ans, count);
            }
            
            else{
                long long curr = key;
                int len = 0;

                while(true){
                    
                    auto it = mp.find(curr);
                    
                    if(it != mp.end() && it->second >= 2){
                        len += 2;
                        curr *= curr; 
                    }
                    else if(it != mp.end() && it->second == 1){
                        len += 1; 
                        break;
                    }
                    else{
                        len--; 
                        break;
                    }
                }
                ans = max(ans, len);
            }
        }
    return ans;
    }
};