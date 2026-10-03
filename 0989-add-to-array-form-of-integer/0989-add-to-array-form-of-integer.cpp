class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {

        int n = num.size();
        int carry = 0;

        for(int i = n - 1; i >= 0; i--) {
            long long temp = num[i] + (k % 10) + carry;

            carry = temp / 10;
            num[i] = temp % 10;

            k /= 10;
        }

        vector<int> ans;

        while(carry > 0 || k > 0) {
            int temp = carry + (k % 10);

            ans.push_back(temp % 10);

            carry = temp / 10;
            k /= 10;
        }

        reverse(ans.begin(), ans.end());

        for(auto ele : num)
            ans.push_back(ele);

        return ans;
    }
};