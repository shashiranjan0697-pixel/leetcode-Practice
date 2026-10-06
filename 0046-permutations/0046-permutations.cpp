class Solution {
public:
    vector<vector<int>> ans;

    void f(vector<int>& nums, vector<bool>& visited, vector<int>& curr) {

        int n = nums.size();

        if(nums.size() == curr.size()){
            ans.push_back(curr);
            return;
        }

        for(int i=0; i<n; i++) {
            if(visited[i]) continue;

            visited[i] = true;
            curr.push_back(nums[i]);

            f(nums, visited, curr);

            visited[i] = false;
            curr.pop_back();            
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false);
        vector<int> curr;
        f(nums, visited, curr);

    return ans;    
    }
};