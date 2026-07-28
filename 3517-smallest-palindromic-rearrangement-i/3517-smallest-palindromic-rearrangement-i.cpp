class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
       vector<int>freq(26,0);
       for(char ch : s){
        freq[ch-'a']++;
       }
       string left, mid, right;
       for(int i=0;i<26;i++){
        left.append(freq[i]/2, char('a'+i));
            if(freq[i]%2){
                mid = char('a'+i);
            }
       }
        right = left;
        reverse(right.begin(),right.end());

    return left+mid+right;
    }
};