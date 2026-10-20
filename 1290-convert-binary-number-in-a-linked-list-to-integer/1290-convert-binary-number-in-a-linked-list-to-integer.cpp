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
    int getDecimalValue(ListNode* head) {
        stack<int> st;
        while(head){
            st.push(head->val);
            head = head->next;
        }
        int ans = 0, start = 1;
        while(!st.empty()){
            ans += st.top() * start;
            start *= 2;
            st.pop();
        }
    return ans;
    }
};