class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while(n>0) {
            sum += n%10;
            n /= 10;
        }
    return sum;
    }
    int countLargestGroup(int n) {
        unordered_map<int, vector<int>> mp;
        int maxi = 0;
        for(int i=1; i<=n; i++){
            int digiSum = digitSum(i);
            mp[digiSum].push_back(i);
            int len = mp[digiSum].size();
            maxi = max(maxi, len);
        }
        int count = 0;
        for(auto &[key , ele] : mp)
            if(ele.size() == maxi) count++;

    return count;
    }
};