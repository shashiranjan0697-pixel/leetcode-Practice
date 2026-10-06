class Solution {
public:
    set<vector<int>>st;

    void f (vector<int>& nums, vector<bool>& visited, vector<int>& curr) {

        if(curr.size() == nums.size()) {
            st.insert(curr);
            return;
        }

        for(int i=0; i < nums.size(); i++) {
            
            if(visited[i]) continue;

            visited[i] = true;
            curr.push_back(nums[i]);

            f(nums, visited, curr);

            visited[i] = false;
            curr.pop_back();

        }

    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();

        vector<bool> visited(n, false);
        vector<int> curr;

        f(nums, visited, curr);

        vector<vector<int>> ans;

        for(auto ele : st) {
            ans.push_back(ele);
        }
    return ans;
    }
};