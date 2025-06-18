class WordDictionary {
private:
    struct Node{
        bool isWord;
        array<Node*, 26> next;
        Node() : isWord(false){
            next.fill(nullptr);
        }
    };

    Node* root;

public:
    WordDictionary() {
        root = new Node();    
    }
    
    void addWord(string word) {
        Node* p = root;
        for(char ch : word){
            int idx = ch - 'a';
            if(!p->next[idx]) p->next[idx] = new Node();
            p = p->next[idx];
        }
        p->isWord = true;
    }
    
    bool search(string word) {
        return dfsSearch(word, 0, root);
    }

    ~WordDictionary(){
        clear(root);
    }

private:
    // 回溯搜索
    bool dfsSearch(const string& word, int pos, Node* p){
        if(!p) return false;
        if(pos == word.size()) {
            return p->isWord;
        }

        char ch = word[pos];
        if(ch == '.'){
            for(int i = 0 ; i < 26 ; i++){
                if(p->next[i] && dfsSearch(word, pos + 1, p->next[i]))
                    return true;
            }
            return false;
        } else {
            int idx = ch - 'a';
            return dfsSearch(word, pos + 1, p->next[idx]);
        }
    }

    void clear(Node* p){
        if(!p) return;
        for(auto c : p->next){
            clear(c);
        }
        delete p;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */