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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prevGroupEnd = &dummy;
        ListNode* curr = head;
        int groupIndex = 1;

        while(curr){
            int count = 0;
            ListNode* temp = curr;

            while(temp && count < groupIndex){
                temp = temp->next;
                count++;
            }

            if(count % 2 == 0){
                ListNode* prev = temp;
                ListNode* node = curr;
                for(int i = 0 ; i < count ; i++){
                    ListNode* nextTemp = node->next;
                    node->next = prev;
                    prev = node;
                    node = nextTemp;
                }

                prevGroupEnd->next = prev;
                prevGroupEnd = curr;
                curr = temp;
            } else {
                for(int i = 0 ; i < count ; i++){
                    prevGroupEnd = curr;
                    curr = curr->next;
                }
            }

            groupIndex++;
        }
        return dummy.next;
    }
};