class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp = head;
        ListNode* prev = new ListNode(-1);
        prev->next = temp;
        ListNode* ans = prev;


        while(temp){
            while( temp && temp->val == val) {
                temp = temp->next;
            }
            
                prev->next = temp;
            if(temp)    temp = temp->next;
            if(prev)    prev = prev->next;
        }
    return ans->next;
    }
};