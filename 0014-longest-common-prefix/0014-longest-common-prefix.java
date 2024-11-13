class Solution {
    public String longestCommonPrefix(String[] strs) {
        // 边界检查
        if (strs == null || strs.length == 0)
            return "";

        // 取第一个字符串作为初始前缀
        String prefix = strs[0];

        // 遍历剩余字符串
        for (int i = 1; i < strs.length; i++) {
            // 当前字符串不以prefix开头时，缩短prefix
            while (strs[i].indexOf(prefix) != 0) {
                prefix = prefix.substring(0, prefix.length() - 1);
                if (prefix.isEmpty())
                    return "";
            }
        }
        return prefix;
    }
}