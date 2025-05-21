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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // ListNode dummy(0);
        // ListNode* curr = &dummy;

        // while(l1 && l2){
        //     if(l1->val < l2->val){
        //         curr->next = new ListNode(l1->val);
        //         l1 = l1->next;
        //     } else {
        //         curr->next = new ListNode(l2->val);
        //         l2 = l2->next;
        //     }
        //     curr = curr->next;
        // }

        // while(l1){
        //     curr->next = new ListNode(l1->val);
        //     l1 = l1->next;
        //     curr = curr->next;
        // }

        // while(l2){
        //     curr->next = new ListNode(l2->val);
        //     l2 = l2->next;
        //     curr = curr->next;
        // }
        // return dummy.next;
        // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        
        ListNode dummy(0);
        ListNode* curr = &dummy;

        while(l1 && l2){
            if(l1->val < l2->val){
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        curr->next = l1 ? l1 : l2;

        return dummy.next;
    }
};