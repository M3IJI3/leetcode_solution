class Solution {
    public boolean isPalindrome(String s) {
        // s = s.replaceAll("[^a-zA-Z0-9]", "").replaceAll("\\s+", "").trim().toLowerCase();

        // int left = 0;
        // int right = s.length() - 1;

        // while(left < right)
        // {
        //     if(s.charAt(left) != s.charAt(right))
        //     {
        //         return false;
        //     }

        //     left++;
        //     right--;
        // }

        // return true;

        // --------------------------------------------------------

        // s = s.replaceAll("[^a-zA-Z0-9]", "").replaceAll("\\s+", "").trim().toLowerCase();
        // StringBuilder sb = new StringBuilder(s);
        // return sb.reverse().toString().equals(s);

        // --------------------------------------------------------

        s = s.toLowerCase();

        int left = 0;
        int right = s.length() - 1;

        while(left < right)
        {
            if(!(s.charAt(left) >= 'a' && s.charAt(left) <= 'z') && !(s.charAt(left) >= '0' && s.charAt(left) <= '9'))
            {
                left++;
                continue;  //continue在这里可以跳过当前循环的剩余代码, 直接执行下一次循环
            }

            if(!(s.charAt(right) >= 'a' && s.charAt(right) <= 'z') && !(s.charAt(right) >= '0' && s.charAt(right) <= '9'))
            {
                right--;
                continue;
            }

            if(s.charAt(left) != s.charAt(right))
            {
                return false;
            }
            
            left++;
            right--;
        }
        
        return true;
    }
}