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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
      ListNode* res = new ListNode();
      ListNode* prvsnode = res;
      ListNode* currnode = head;
        
        while(head && head->next){
            ListNode* temp = head->next;
            head->next=head->next->next;
            prvsnode->next=temp;
            temp->next=head;
            prvsnode=head;
            head=head->next;
        }
        return res->next;
    }
};