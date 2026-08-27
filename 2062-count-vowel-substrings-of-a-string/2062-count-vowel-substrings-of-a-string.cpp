class Solution {
public:
    int countVowelSubstrings(string word) {
        int n = word.size();
        int ans = 0;

        unordered_set<char> vowels = {
            'a', 'e', 'i', 'o', 'u'
        };

        for (int i = 0; i < n; i++) {

            unordered_set<char> st;

            for (int j = i; j < n; j++) {

                // Consonant -> this starting position is finished
                if (!vowels.count(word[j]))
                    break;

                st.insert(word[j]);

                // All 5 vowels present
                if (st.size() == 5)
                    ans++;
            }
        }

        return ans;
    }
};