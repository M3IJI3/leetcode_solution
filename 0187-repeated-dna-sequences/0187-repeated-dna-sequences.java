class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        List<String> ans = new ArrayList<>();
        String currentStr = "";

        HashMap<String, Integer> map = new HashMap<>();

        for(int i = 0 ; i <= s.length() - 10; i++)
        {
            currentStr = s.substring(i, i + 10);
            map.put(currentStr, map.getOrDefault(currentStr, 0) + 1);
            currentStr = "";
        }

        for(String key : map.keySet())
        {
            if(map.get(key) > 1)
            {
                ans.add(key);
            }
        }

        return ans;
    }
}