class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        map<string, int> m;

        int n = s.length();
        int i = 0, j = 0;
        int count = 0;

        while (j < n) {

            if (s[j] == '1')
                count++;

            while (count > k) {
                if (s[i] == '1')
                    count--;

                i++;
            }

            if (count == k) {

                while (i < j && s[i] == '0')
                    i++;

                string c = s.substr(i, j - i + 1);

                cout << c << ", ";

                m[c] = c.length();
            }

            j++;
        }

        string ans = "";

        for (auto &[str, len] : m) {
            if (ans.empty() ||
                len < ans.length() ||
                (len == ans.length() && str < ans)) {
                ans = str;
            }
        }

        return ans;
    }
};