class Solution {
public:
    char findTheDifference(string s, string t) {
        for (char c : t) {
            size_t pos = s.find(c);
            if (pos != string::npos)
                s.erase(pos, 1);
            else
                return c;
        }
        return ' ';
    }
};