class Solution {
    public boolean isSubsequence(String s, String t) {
        // if (s.length() == 0)
        //     return true;

        // int s_ptr = 0;

        // for (int i = 0; i < t.length(); i++) {

        //     if (s_ptr < s.length()) {
        //         if (t.charAt(i) == s.charAt(s_ptr) && s_ptr < s.length()) {
        //             s_ptr++;
        //         }
        //     }
        // }
        // return s_ptr == s.length();

        int i = 0, j = 0;
        while(i < s.length() && j < t.length())
        {
            if(s.charAt(i) == t.charAt(j))
            {
                i++;
            }
            j++;
        }
        return i == s.length();
    }
}