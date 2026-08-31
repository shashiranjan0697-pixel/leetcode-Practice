/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> idx;
        int index = 2;
        ListNode* curr = head->next;
        ListNode* prev = head;
        while(curr){
            if(curr->next && curr->val < prev->val && curr->val < curr->next->val){
                idx.push_back(index);
            }
            if(curr->next && curr->val > prev->val && curr->val > curr->next->val){
                idx.push_back(index);
            }
        index++;
        prev = curr;
        curr = curr->next;
        }

        if(idx.size() < 2) return {-1, -1};

        sort(idx.begin(), idx.end());

        for(auto ele : idx) cout<<ele<<", ";

        int n = idx.size();

        int maxi = idx[n-1] - idx[0];
        int mini = idx[n-1];
        for(int i=1; i<n; i++) {
            mini = min(mini, (idx[i]-idx[i-1]) );
        }
    return {mini, maxi};
    }
};