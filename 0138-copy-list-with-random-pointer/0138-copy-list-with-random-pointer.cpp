/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        
        Node* curr = head;
        while(curr){
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = curr->next->next;
        }

        curr = head;
        while(curr){
            if(curr->random){
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        Node dummy(0);
        Node* copyCurr = &dummy;
        curr = head;
        while(curr){
            Node* copy = curr->next;
            copyCurr->next = copy;
            copyCurr = copy;

            curr->next = copy->next;
            curr = curr->next;
        }

        return dummy.next;
    }
};

// if(!head) return nullptr;

// ListNode* curr = head;
// unordered_map<Node*, Node*> old2new;
// while(curr){
//     // 旧节点          新节点  
//     old2new[curr] = new Node(curr->val);
//     curr = curr->next;
// }

// curr = head;
// while(curr){
//     // A'->next = B'
//     old2new[curr]->next = old2new[curr->next];
//     old2new[curr]->random = old2new[curr->random];
//     curr = curr->next;
// }

// return old2new[head];
















