class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        // unordered_map<char, int> freq1, freq2;

        // for(char c : name)  freq1[c]++;
        // for(char c : typed) freq2[c]++;

        // for(auto& [letter, freq] : freq1){
        //     // 如果没有名字里的字符
        //     if(!freq2.count(letter)) return false;
        //     else {
        //         // 如果有, 判断是否出现次数正确
        //         if(freq > freq2[letter]) return false;
        //     }
        // }
        // return true;
        // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

        int i = 0, j = 0;
        
        while(j < typed.size()){
            if(i < name.size() && name[i] == typed[j]){
                // 字符匹配 正常推进两个指针
                i++;
                j++;
            } else if(j > 0 && typed[j] == typed[j - 1]) {
                // 当前字符是长按
                j++;
            } else {
                return false;
            }
        }

        return i == name.size();
    }
};