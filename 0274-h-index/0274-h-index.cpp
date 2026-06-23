class Solution {
public:
    int hIndex(vector<int>& citations) {

        sort(citations.begin(), citations.end(), [] (int a, int b){
            return a>b;
        });
        int count =1;
        for(int i=0;i<citations.size();i++){
            if(citations[i]>=count){
                count++;
            }
            else break;
        }

    return count-1;
    }
};