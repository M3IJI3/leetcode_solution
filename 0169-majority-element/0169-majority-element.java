class Solution {
    public int majorityElement(int[] nums) {
        // HashMap<Integer, Integer> map = new HashMap<>();
        // int res = 0;
        // int majority = 0;

        // for(int n: nums)
        // {
        // map.put(n, 1 + map.getOrDefault(n, 0));

        // if(map.get(n) > majority)
        // {
        // res = n;
        // majority = map.get(n);
        // }
        // }
        // return res;

        int res = 0;
        int majority = 0;

        for (int n : nums) {
            if (majority == 0) {
                res = n;
            }

            majority += n == res ? 1 : -1;
        }
        return res;
    }
}