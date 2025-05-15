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

        unordered_map<Node*, Node*> old2new;

        // 第一次遍历: 创建所有新节点
        Node* curr = head;
        while(curr){
            old2new[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // 第二次遍历: 设置next和random指针
        curr = head;
        while(curr){
            old2new[curr]->next = old2new[curr->next];
            old2new[curr]->random = old2new[curr->random];
            curr = curr->next;
        }
        return old2new[head];
    }
};