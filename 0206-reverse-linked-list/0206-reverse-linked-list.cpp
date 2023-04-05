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
    ListNode* fn(ListNode* prvs,ListNode* curr){
        if(curr==NULL)return prvs;
        ListNode* temp = curr->next;
        curr->next=prvs;
        prvs = curr;
        curr=temp;
        return fn(prvs,curr);
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* prvs = NULL;
       return fn(prvs,head);
    }
};