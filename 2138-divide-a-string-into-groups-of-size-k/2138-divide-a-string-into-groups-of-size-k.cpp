class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int extra = k - s.size() % k;
        if(extra != k) s += string(extra, fill);

        vector<string> result;
        string temp;
        
        for(int i = 0 ; i < s.size() ; i++){
            temp += s[i];

            if(temp.size() == k){
                result.push_back(temp);
                temp.clear();
            }
        }

        return result;
    }
};