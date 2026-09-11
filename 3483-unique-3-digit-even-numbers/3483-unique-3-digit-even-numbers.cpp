class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        unordered_set<int> st;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(digits[i] == 0) break;
                for(int k=0; k<n; k++) {
                    if(i==j || i==k || k==j) continue;
                    int temp = digits[i] * 100 + digits[j] * 10 + digits[k];
                    if(temp%2 == 0) st.insert(temp);
                }
            }
        }
    return st.size();
    }
};