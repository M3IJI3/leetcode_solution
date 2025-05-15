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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left == right) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        // 定位到left的前一个节点
        for(int i = 1 ; i < left ; i++){
            prev = prev->next;
        }

        // 开始原地反转
        ListNode* curr = prev->next; // 当前正在处理的节点
        for(int i = 0 ; i < right - left; i++){
            ListNode* next = curr->next;
            curr->next = next->next; // 这一步把 2 指向 4
            next->next = prev->next; // 3 指向 2
            prev->next = next; //  最后 1 指向 3
        }

        return dummy.next;
    }
};