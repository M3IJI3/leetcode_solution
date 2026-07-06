class CombinationIterator {
    string s;
    int k;
    queue<string> q;
public:
    CombinationIterator(string characters, int combinationLength) {
        this->s = characters;
        this->k = combinationLength;
        string path = "";
        dfs(path, 0);
    }
    
    string next() {
        if(hasNext()){
            string ans = q.front(); q.pop();
            return ans;
        }
        return "";
    }
    
    bool hasNext() {
        return !q.empty();
    }

    void dfs(string& path, int start){
        if(path.size() == k){
            q.push(path);
            return;
        }

        for(int i = start ; i < s.size() ; i++){
            path.push_back(s[i]);
            dfs(path, i + 1);
            path.pop_back();
        }
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */