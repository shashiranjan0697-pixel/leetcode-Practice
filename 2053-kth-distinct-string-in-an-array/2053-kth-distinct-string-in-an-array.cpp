class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;
        for(auto ele : arr) mp[ele]++;
        int count = 1;
        for(auto ele : arr) {
            if(count == k && mp[ele] == 1) return ele;
            if(mp[ele] == 1) count++;
        }
    return "";
    }
};