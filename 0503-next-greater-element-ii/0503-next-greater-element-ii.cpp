class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ng(n, -1);
        stack<int> s;
        for(int i=0; i<n*2; i++){
            int index = i%n;
            while(!s.empty() && nums[index] > nums[s.top()]){
                ng[s.top()] = nums[index];
                s.pop();
            }
            
        s.push(index);
        }
    return ng;
    }
};