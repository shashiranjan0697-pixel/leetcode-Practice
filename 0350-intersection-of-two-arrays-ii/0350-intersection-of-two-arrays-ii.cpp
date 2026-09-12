class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        for(auto ele : nums1) mp[ele]++;
        nums1.clear();
        for(auto ele : nums2) {
            if(mp.find(ele)!=mp.end(ele)){
                nums1.push_back(ele);
                mp[ele]--;
                if(mp[ele] == 0) mp.erase(ele);
            }
        }
    return nums1; 
    }
};