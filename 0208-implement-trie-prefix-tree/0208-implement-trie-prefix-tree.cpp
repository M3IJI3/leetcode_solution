class Trie {
private:
    struct Node{
        bool endOfWord;
        array<Node*, 26> next;      // 标记是否有单词在此结束
        Node() : endOfWord(false){  // 指向26个子节点(a-z)
            next.fill(nullptr);
        }
    };

    Node* root; // 根节点
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* p = root;
        for(char c : word){
            int idx = c - 'a';
            if(!p->next[idx]){
                p->next[idx] = new Node();
            }
            p = p->next[idx];
        }
        p->endOfWord = true;
    }
    
    bool search(string word) {
        Node* p = root;
        for(char c : word){
            int idx = c - 'a';
            if(!p->next[idx]) return false;
            p = p->next[idx];
        }
        return p->endOfWord;
    }
    
    bool startsWith(string prefix) {
        Node* p = root;
        for(char c : prefix){
            int idx = c - 'a';
            if(!p->next[idx]) return false;
            p = p->next[idx];
        }
        return true;
    }

    ~Trie(){
        clear(root);
    }

private:
    void clear(Node* p){
        if(!p) return;
        for(auto child : p->next){
            clear(child);
        }
        delete p;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */