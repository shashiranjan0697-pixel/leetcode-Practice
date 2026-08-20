class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1, arr2, res;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for(int i=2; i<nums.size(); i++){
            int a1 = arr1.size()-1, a2 = arr2.size()-1;
            if(arr1[a1] > arr2[a2]) arr1.push_back(nums[i]);
            else arr2.push_back(nums[i]);
        }
    res = arr1;
    for (auto x : arr2) res.push_back(x);
    
    return res;
    }
};