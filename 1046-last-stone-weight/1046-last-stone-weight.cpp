class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq(stones.begin(),stones.end());
        
        while(pq.size()>1){
            int top = pq.top();
            pq.pop();
            int top1 = pq.top();
            pq.pop();
            if(top == top1) continue;
            else{
                pq.push(abs(top-top1));
            }
        }
    return pq.size() == 0 ? 0 : pq.top();
    }
};