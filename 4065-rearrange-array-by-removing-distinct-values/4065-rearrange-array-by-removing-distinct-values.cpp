class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;
        vector<int> ans;

        for(auto ele : nums) 
            mp[ele]++;
        
        while(ans.size() < n) {
            for(auto &[ele, freq] : mp) {
                if(freq > 0){
                    ans.push_back(ele);
                    mp[ele]--;
                }
            }
        }
    return ans;    
    }
};