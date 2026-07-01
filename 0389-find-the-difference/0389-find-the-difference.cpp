class Solution {
public:
    char findTheDifference(string s, string t) {
        for (char c : t) {
            int pos = s.find(c);
            if (pos != string::npos)
                s.erase(pos, 1);
            else
                return c;
        }
        return ' ';
    }
};