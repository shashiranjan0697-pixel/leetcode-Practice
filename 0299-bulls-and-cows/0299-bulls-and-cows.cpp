class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> mp;
        unordered_set<int> st;
        int cow = 0;
        int bull = 0;
        for(int i=0; i<secret.length(); i++){
            if(secret[i] == guess[i]){
                bull++;
                st.insert(i);
            }
            else{
                mp[secret[i]]++;
            }
        }
        for(int i=0; i<guess.length(); i++){
            if(!st.count(i)){
               if(mp[guess[i]] > 0){
                  mp[guess[i]]--;
                  cow++;
               } 
               else mp.erase(guess[i]);
            }
        }
    return to_string(bull) + "A" + to_string(cow) + "B";
    }
};