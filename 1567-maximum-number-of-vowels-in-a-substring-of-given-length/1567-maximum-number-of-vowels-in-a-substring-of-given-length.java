class Solution {
    public int maxVowels(String s, int k) {
        // TLE
        // Set<Character> set = new HashSet<>();
        // set.add('a');
        // set.add('e');
        // set.add('i');
        // set.add('o');
        // set.add('u');

        // int left = 0;
        // int right = k - 1;
        // int count = 0;
        // int maxLetters = 0;
        
        // while(right < s.length())
        // {
        //     for(int i = left ; i <= right ; i++)
        //     {
        //         if(set.contains(s.charAt(i)))
        //         {
        //             count++;
        //         }
        //     }
        //     maxLetters = Math.max(maxLetters, count);
        //     if(maxLetters == k) break;
        //     left++;
        //     right++;
        //     count = 0;
        // }

        // return maxLetters;

        // ---------------------------------------------
        int n = s.length();
        int ans = 0;
        int window = 0;

        for(int i = 0 ; i < k ; i++)
        {
            if(isVowel(s.charAt(i)))
            {
                window++;
            }
        }
        ans = window;

        for(int right = k ; right < n ; right++)
        {
            if(isVowel(s.charAt(right)))
            {
                window++;
            }

            if(isVowel(s.charAt(right - k))) // 向右扩张边界的同时判断最左字符是否是元音
            {
                window--;  // 如果最左是元音 那就减1
            }
            ans = Math.max(ans, window);
        }
        return ans;
    }

    public boolean isVowel(char ch)
    {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            return true;
        }
        return false;
    }
}