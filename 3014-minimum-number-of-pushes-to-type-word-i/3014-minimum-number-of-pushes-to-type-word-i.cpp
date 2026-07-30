class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int> mp;
        int cost = 1;
        for(auto ele : word){
            if(mp.find(ele)==mp.end()) mp[ele]=cost;
            if(mp.size()%8==0) cost++;
        }
        int count =0;
        for(auto ele : word){
            count+=mp[ele];
        }
    return count;
    }
};