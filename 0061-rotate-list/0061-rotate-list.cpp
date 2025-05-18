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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;

        // 1. 计算链表长度
        ListNode* tail = head;
        int len = 1;
        while(tail->next){
            tail = tail->next;
            len++;
        }

        // 2. 缩小旋转次数
        k = k % len;
        if(k == 0) return head;

        // 3 成环
        tail->next = head;

        // 4. 找新尾结点
        ListNode* newTail = head;
        for(int i = 0 ; i < len - k - 1 ; i++){
            newTail = newTail->next;
        }

        // 5. 断开
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};