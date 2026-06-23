class Solution {
public:
    int hIndex(vector<int>& citations) {
        int count =1;
        for(int i=citations.size()-1;i>=0;i--){
            if(citations[i]>=count){
                count++;
            }
            else break;
        }

    return count-1;
    }
};