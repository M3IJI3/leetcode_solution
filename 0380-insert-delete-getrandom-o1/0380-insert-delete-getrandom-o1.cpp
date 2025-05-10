class RandomizedSet {
private:
    unordered_map<int, int> valtoIndex; // 记录 val 对应的下标
    vector<int> value;                  // 存储所有的元素

public:
    RandomizedSet() {
        // 构造函数 无须初始化其他
    }
    
    bool insert(int val) {
        if(valtoIndex.count(val)) return false;

        value.push_back(val);
        valtoIndex[val] = value.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(!valtoIndex.count(val)) return false;

        int valIndex = valtoIndex[val];
        int lastVal = value.back();

        value[valIndex] = lastVal;
        valtoIndex[lastVal] = valIndex;

        value.pop_back();
        valtoIndex.erase(val);

        return true;
    }
    
    int getRandom() {
        int i = rand() % value.size();
        return value[i];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */