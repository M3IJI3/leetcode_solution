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
        if(!head) return nullptr;
        
        // 1. 计算链表长度
        int len = 1;
        ListNode* tail = head;
        while(tail->next){
            tail = tail->next;
            len++;
        }

        // 2. 优化旋转次数
        k = k % len;
        if(k == 0) return head;

        // 3. 成环
        tail->next = head;

        // 4. 找新尾节点
        for(int i = 0; i < len - k; i++){
            tail = tail->next;
        }

        ListNode* newHead = tail->next;
        tail->next = nullptr;

        return newHead;
    }
};