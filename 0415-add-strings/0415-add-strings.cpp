class Solution {
public:
    string addStrings(string num1, string num2) {

        string ans = "";
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {

            int a = (i >= 0) ? num1[i] - '0' : 0;
            int b = (j >= 0) ? num2[j] - '0' : 0;

            int sum = a + b + carry;

            carry = sum / 10;
            sum %= 10;

            ans.push_back(sum + '0');

            i--;
            j--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};