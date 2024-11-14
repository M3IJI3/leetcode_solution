class Solution {
    public boolean isPalindrome(String s) {
        s = s.replaceAll("[^a-zA-Z0-9]", "").replaceAll("\\s+", "").trim().toLowerCase();
        System.out.println(s);

        int left = 0;
        int right = s.length() - 1;

        while(left < right)
        {
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