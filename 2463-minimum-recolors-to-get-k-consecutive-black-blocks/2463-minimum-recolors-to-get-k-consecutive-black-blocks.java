class Solution {
    public int minimumRecolors(String blocks, int k) {
        int left = 0;
        int right = left + k - 1;
        int min = Integer.MAX_VALUE;
        HashMap<Character, Integer> map = new HashMap<>();

        while(right < blocks.length())
        {
            for(int i = left ; i <= right ; i++)
            {
                map.put(blocks.charAt(i), map.getOrDefault(blocks.charAt(i), 0) + 1);   
            }
            
            if(!map.containsKey('W'))
            {
                return 0;
            }
            else
            {
                min = Math.min(min, map.get('W'));
            }
            map.clear();
            left++;
            right++;
            
        }
        return min;
    }
}