class Solution {
    public boolean isIsomorphic(String s, String t) {
        HashMap<Character, Character> map1 = new HashMap<>();
        HashMap<Character, Character> map2 = new HashMap<>();

        int n = s.length();

        for(int i = 0 ; i < n ; i++)
        {
            if(map1.containsKey(s.charAt(i)) && map1.get(s.charAt(i)) != t.charAt(i))
            {
                return false;
            }
            map1.put(s.charAt(i), t.charAt(i));
        }
        for(int i = 0 ; i < n ; i++)
        {
            if(map2.containsKey(t.charAt(i)) && map2.get(t.charAt(i)) != s.charAt(i))
            {
                return false;
            }
            map2.put(t.charAt(i), s.charAt(i));
        }
        return true;
    }
}