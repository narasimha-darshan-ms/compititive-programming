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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {   
        ListNode *result = new ListNode;
        ListNode *header = result;
        int remainder;
        
        result->val = (l1->val + l2->val) % 10;
        remainder = (l1->val + l2->val) / 10;
        result->next = NULL; l1 = l1->next; l2 = l2->next;
        
        for(; l1 != NULL && l2 != NULL ; l1 = l1->next, l2 = l2->next){
            ListNode *res = new ListNode;
            result->next = res; 
            res->val = (remainder + l1->val + l2->val) % 10;
            remainder = (remainder + l1->val + l2->val) / 10;
            res->next = NULL;
            result = result->next;
        }
        while (l1 == NULL && l2 != NULL){
            ListNode *res = new ListNode;
            result->next = res; 
            res->val = (remainder + l2->val) % 10;
            remainder = (remainder + l2->val) / 10;
            res->next = NULL;
            
            result = result->next; 
            l2 = l2->next;
        }   
        while (l1 != NULL && l2 == NULL){
            ListNode *res = new ListNode;
            result->next = res; 
            res->val = (remainder + l1->val) % 10;
            remainder = (remainder + l1->val) / 10;
            res->next = NULL;
            
            result = result->next;
            l1 = l1->next;
        }
        if (remainder != 0 ){
            ListNode *res = new ListNode;
            res-> val = remainder; res->next = NULL;
            result->next = res; 
        }
        return header;
    }
};
