class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_set<int> st(friends.begin(), friends.end());
        int i = 0;
        for(int x : order){
            if(st.find(x)!=st.end()){
                friends[i] = x;
                i++;
            }
        }
    return friends;
    }
};