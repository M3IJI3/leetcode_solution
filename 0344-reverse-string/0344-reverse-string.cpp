class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;

        while(left < right){
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;

            // 更新左右指针位置
            left++,
            right--;
        }
    }
};