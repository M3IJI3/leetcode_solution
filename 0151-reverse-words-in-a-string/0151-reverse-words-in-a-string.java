class Solution {
    public String reverseWords(String s) {
        String[] strs = s.split("\\s+");
        StringBuilder sb = new StringBuilder();

        for(int i = strs.length - 1 ; i >= 0 ; i--)
        {
            sb.append(strs[i] + " ");
        }
        return sb.toString().trim();
    }
}