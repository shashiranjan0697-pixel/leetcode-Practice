class Solution {
public:
    int distributeCandies(vector<int>& arr) {
        unordered_set<int> st(arr.begin(), arr.end());
        int n = arr.size();
        int sz = st.size();
    return min(n/2, sz);
    }
};