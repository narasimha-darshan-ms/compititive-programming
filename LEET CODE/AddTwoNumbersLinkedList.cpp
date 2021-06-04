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
        pair<ListNode*, int> result = getresult(l1, l2);
        if(result.second == 0)  return result.first;
        ListNode *node = new ListNode;
        node->next = result.first; node->val = result.second;
        return node;
    }
    
    pair<ListNode*, int> getresult(ListNode* l1, ListNode* l2){
        int sum, remainder;
        ListNode *node = new ListNode;
        pair<ListNode*, int> res, ret_res;
        if (l1->next == NULL && l2->next == NULL){
            node->next = NULL; node->val = (res.second + l1->val + l2->val) % 10;
            ret_res = make_pair(node, (res.second + l1->val + l2->val) / 10);
        }
        else if (l1->next != NULL && l2->next != NULL){
            res = getresult(l1->next, l2->next);
            node->next = res.first; node->val = (res.second + l1->val + l2->val) % 10;
            ret_res = make_pair(node, (res.second + l1->val + l2->val) / 10);
        }
        else if (l1->next == NULL && l2->next != NULL){
            res = getresult(l1,l2->next);
            node->next = res.first; node->val = (res.second + l1->val + l2->val) % 10;
            ret_res = make_pair(node, (res.second + l1->val + l2->val) / 10);
        }
        else if (l1->next != NULL && l2->next == NULL){
            res = getresult(l1->next,l2);
            node->next = res.first; node->val = (res.second + l1->val + l2->val) % 10;
            ret_res = make_pair(node, (res.second + l1->val + l2->val) / 10);
        }
        
        return ret_res;
    }
};
