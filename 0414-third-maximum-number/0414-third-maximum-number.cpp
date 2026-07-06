class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue <int, vector<int>, greater<int> > pq;
        unordered_set<int> st(nums.begin(),nums.end());
        int maxi = INT_MIN;
        for(auto x : st){
            maxi = max(maxi, x);
            pq.push(x);
            if(pq.size()>3) pq.pop();
        }
    return pq.size()==3 ? pq.top() : maxi;
    }
};