class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int count = 0;

        int a = 0, b = 0, c = 0;
        int i = 0;

        for (int j = 0; j < n; j++) {
            if (s[j] == 'a') a++;
            else if (s[j] == 'b') b++;
            else c++;

            while (a > 0 && b > 0 && c > 0) {
                count += (n - j);

                if (s[i] == 'a') a--;
                else if (s[i] == 'b') b--;
                else c--;

                i++;
            }
        }

        return count;
    }
};