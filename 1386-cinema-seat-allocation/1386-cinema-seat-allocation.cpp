class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int> > mp;
        for(auto ele : reservedSeats){
            mp[ele[0]].insert(ele[1]);
        }
        int count = (n-mp.size())*2;
        for(auto &[row, st] : mp){
            bool left = !st.count(2) && !st.count(3) && !st.count(5) && !st.count(4);

            bool mid = !st.count(7) && !st.count(6) && !st.count(5) && !st.count(4);
            
            bool right = !st.count(7) && !st.count(6) && !st.count(8) && !st.count(9);

        if(left && right) count += 2;
        else if (left || mid || right) count += 1;
        }
        
    return count;
    }
};