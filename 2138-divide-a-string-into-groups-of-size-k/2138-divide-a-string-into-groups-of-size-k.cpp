class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int extra = k - s.size() % k;
        if(extra != k) s += string(extra, fill);

        vector<string> result;
        string temp;
        int i = 0;

        while(i <= s.size() - k){
            temp = s.substr(i, k);
            result.push_back(temp);
            i += k;
        }
        
        return result;
    }
};