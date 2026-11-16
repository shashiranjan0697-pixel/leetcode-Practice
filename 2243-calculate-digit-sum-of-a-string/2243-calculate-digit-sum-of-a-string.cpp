
class Solution {
public:
    int digitSum(int n) {
        int sum = 0;

        while(n > 0) {
            sum += n % 10;
            n /= 10;
        }

        return sum;
    }

    string digitSum(string s, int k) {
        while(s.length() > k) {
            string ans = "";

            int n = s.length();

            for(int i = 0; i < n; i += k) {
                string str = s.substr(i, k);

                int temp = 0;

                for(char c : str) {
                    temp += c - '0';
                }

                ans += to_string(temp);
            }

            s = ans;
        }

        return s;
    }
};
