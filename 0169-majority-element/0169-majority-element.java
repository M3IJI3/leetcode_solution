class Solution {
    public int majorityElement(int[] nums) {
        // int majority = 0;
        // int res = 0;
        // HashMap<Integer, Integer> map = new HashMap<>();

        // for(int n: nums)
        // {
        // map.put(n, map.getOrDefault(0, n) + 1);

        // if(map.get(n) > majority)
        // {
        // res = n;
        // majority = map.get(n);
        // }
        // }

        // return res;
        // --------------------------
        // | MOORE VOTING ALGORITHM |
        // --------------------------

        int res = 0;
        int majority = 0;

        for (int n : nums) {
            if (majority == 0)  // 如果majority为0, 可以
                res = n;        // 重新选择个数字进行"投票"

            majority += n == res ? 1 : -1; // 如果后续遍历数字与前一轮数字res一致, 则"票数"加1. 反之减1
        }

        return res;
    }
}