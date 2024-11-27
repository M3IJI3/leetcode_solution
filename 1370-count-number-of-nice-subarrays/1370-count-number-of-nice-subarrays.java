class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
        int n = nums.length;
        int[] count = new int[n + 1];
        count[0] = 1; // 初始化为1，处理边界情况
        
        int oddCount = 0; // 记录奇数个数
        int result = 0;
        
        for (int num : nums) {
            // 统计奇数个数
            oddCount += num % 2;
            
            // 如果窗口内奇数个数大于等于k，则计算优美子数组数量
            if (oddCount >= k) {
                result += count[oddCount - k];
            }
            
            // 记录当前奇数个数出现的频次
            count[oddCount]++;
        }
        
        return result;
    }
}