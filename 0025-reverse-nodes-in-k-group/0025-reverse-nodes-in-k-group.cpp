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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = 1;
        ListNode* temp = head;
        while (temp->next) {
            temp = temp->next;
            n++;
        }

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prevGroupEnd = &dummy;
        ListNode* curr = head;

        int groupCount = n / k;
        while (groupCount > 0) {
            ListNode* groupHead = curr;
            ListNode* prev = nullptr;

            for (int i = 0; i < k; i++) {
                ListNode* nextTemp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextTemp;
            }

            prevGroupEnd->next = prev;
            groupHead->next = curr;

            prevGroupEnd = groupHead;

            groupCount--;
        }
        return dummy.next;
    }
};