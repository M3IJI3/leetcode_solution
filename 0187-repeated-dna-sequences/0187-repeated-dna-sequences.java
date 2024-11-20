class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        // List<String> ans = new ArrayList<>();
        // String currentStr = "";

        // HashMap<String, Integer> map = new HashMap<>();

        // for (int i = 0; i <= s.length() - 10; i++) {
        // currentStr = s.substring(i, i + 10);
        // map.put(currentStr, map.getOrDefault(currentStr, 0) + 1);
        // }

        // for (String key : map.keySet()) {
        // if (map.get(key) > 1) {
        // ans.add(key);
        // }
        // }

        // return ans;

        // ----------------------------------------------------

        Set seen = new HashSet(), repeated = new HashSet();
        int n = s.length();

        for (int i = 0; i <= n - 10; i++) {
            String ten = s.substring(i, i + 10);
            if (!seen.add(ten)) {
                repeated.add(ten);
            }
        }
        return new ArrayList(repeated);

        // -----------------------------------------------------

        // Set set = new HashSet(), res = new HashSet();
        // int n = s.length();
        // if (n < 10 || n > 10000) {
        // return new ArrayList(res);
        // }
        // for (int i = 0; i + 9 < n; i++) {
        // String ten = s.substring(i, i + 10);
        // if (!set.add(ten))
        // res.add(ten);
        // }
        // return new ArrayList(res);
    }
}