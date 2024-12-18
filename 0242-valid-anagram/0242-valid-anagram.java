class Solution {
    public boolean isAnagram(String s, String t) {
        // if(s.length() != t.length()) return false;

        // Map<Character, Integer> sMap = new HashMap<>();
        // Map<Character, Integer> tMap = new HashMap<>();

        // int len = s.length();

        // for(int i = 0 ; i < len ; i++)
        // {
        // sMap.put(s.charAt(i), sMap.getOrDefault(s.charAt(i), 0) + 1);
        // tMap.put(t.charAt(i), tMap.getOrDefault(t.charAt(i), 0) + 1);
        // }
        // return sMap.equals(tMap);

        // ------------------------------------------------

        // if(s.length() != t.length()) return false;

        // int[] arr1 = new int[26];
        // int[] arr2 = new int[26];

        // int len = s.length();

        // for(int i = 0 ; i < len ; i++)
        // {
        // arr1[s.charAt(i) - 'a']++;
        // arr2[t.charAt(i) - 'a']++;
        // }
        // return Arrays.equals(arr1, arr2);

        // -------------------------------------------------

        if (s.length() != t.length())
            return false;

        int[] arr = new int[26];
        int len = s.length();

        for (int i = 0; i < len; i++) {
            arr[s.charAt(i) - 'a']++;
        }

        for (int i = 0; i < len; i++) {
            arr[t.charAt(i) - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (arr[i] != 0) {
                return false;
            }
        }

        return true;
    }
}