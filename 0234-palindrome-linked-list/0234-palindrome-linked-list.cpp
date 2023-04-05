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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        
        
        // reverse second half of linked list
        ListNode* temp = slow;
        ListNode* prev = nullptr;
        while(temp ){
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            
            temp = next;       
        }


        // Comparing reverse list & initial half original list
        
        ListNode* head2 = prev; // starting node of reversed list
        
        while(head != slow){
            if(head->val != head2->val){
                return false;
            }
            head = head->next;
            head2 = head2->next;
        }
        return true;
        
        
    }
};