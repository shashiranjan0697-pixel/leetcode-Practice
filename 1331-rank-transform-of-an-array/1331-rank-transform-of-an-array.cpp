class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ans(arr.begin(),arr.end());
        unordered_map<int,int> mp;
        sort(arr.begin(),arr.end());
        int rank = 1;
        for(int i=0;i<arr.size();i++){
            if(mp.find(arr[i])!=mp.end()) continue;
            else{
                mp[arr[i]] = rank;
                    rank++;
                }
        }
        for(int i=0;i<arr.size();i++){
            ans[i] = mp[ans[i]];
        }
    return ans;
    }
};