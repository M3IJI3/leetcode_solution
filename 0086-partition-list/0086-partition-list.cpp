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
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy1(0);
        ListNode dummy2(0);

        ListNode* smaller = &dummy1;
        ListNode* bigger = &dummy2;

        ListNode* curr = head;
        while(curr){
            if(curr->val < x){
                smaller->next = curr;
                smaller = curr;
            } else {
                bigger->next = curr;
                bigger = curr;
            }
            curr = curr->next;
        }

        bigger->next = nullptr;
        smaller->next = dummy2.next;

        return dummy1.next;
    }
};