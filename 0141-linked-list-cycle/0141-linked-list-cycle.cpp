/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)return false;
        ListNode* slow = head , *fast = head->next;
        while(slow!=NULL && fast!=NULL && slow!=fast){
            slow=slow->next;
            if(fast->next==NULL || fast->next->next==NULL)return false;
            fast=fast->next->next;
        }
        if(slow==NULL || fast==NULL || slow!=fast)return false;
        return true;
    }
};