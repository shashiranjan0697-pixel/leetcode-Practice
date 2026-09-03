class Solution {
public:
    bool uniformArray(vector<int>& num) {

        int odd = INT_MAX, even = INT_MAX;

        for(auto ele : num){

            if(ele%2 == 0) even = min(even, ele);

            else odd = min(odd, ele);

        }

        if(odd == INT_MAX || even == INT_MAX) return true;

        for(auto ele : num){

            if(ele%2 == 0 && (ele-odd) < 1) {
                return false;
            }
            
        }
        
    return true;    
    }
};