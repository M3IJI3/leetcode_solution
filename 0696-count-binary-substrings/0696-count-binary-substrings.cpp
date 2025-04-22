class Solution {
public:
    int countBinarySubstrings(string s) {
        // prev -> 上一组字符的数量
        // curr -> 当前组字符的数量
        // ans  -> 符合结果的字符串数量
        int prev = 0, curr = 1, ans = 0;

        // 从 i = 1 开始遍历,
        // 与前一个元素比较发现是否相等
        for(int i = 1 ; i < s.size() ; i++){
            if(s[i] == s[i-1]){
                // 如果相等, curr 长度加 1
                curr++;
            } else {
                // 否则, 
                ans += min(prev, curr);
                prev = curr;
                curr = 1;
            }
        }

        ans += min(prev, curr);
        return ans;
    }
};