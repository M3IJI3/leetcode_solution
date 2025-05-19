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
    ListNode* deleteMiddle(ListNode* head) {
        // 计算链表长度
        int n = 0;
        ListNode* start = head;
        while(start){
            start = start->next;
            n++;
        }

        if(n == 1) return nullptr;

        // 找到中点
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        // 判断两种情况
        ListNode* curr = head;
        if(n % 2 != 0){
            for(int i = 1 ; i < n / 2 ; i++){
                curr = curr->next;
            }
            curr->next = slow->next;
        } else {
            slow->next = slow->next->next;
        }

        return head;
    }
};