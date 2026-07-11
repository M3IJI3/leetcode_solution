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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* currA = headA, *currB = headB;
        while(currA != currB){
            currA = (currA == nullptr) ? headB : currA->next;
            currB = (currB == nullptr) ? headA : currB->next;
        }
        return currA;
    }
};