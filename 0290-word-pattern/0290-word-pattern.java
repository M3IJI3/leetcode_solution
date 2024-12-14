class Solution {
    public boolean wordPattern(String pattern, String s) {
        String[] words = s.split(" ");

        if(words.length != pattern.length()) return false;
        
        Map index = new HashMap();
        for (Integer i = 0; i < words.length; i++) // 使用Integer作为类型
            if (index.put(pattern.charAt(i), i) != index.put(words[i], i))
                return false;
        return true;
    }
}